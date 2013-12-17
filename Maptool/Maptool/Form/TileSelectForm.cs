using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Maptool
{
    public partial class TileSelectForm : Form
    {
        public int index = -1;
        int brush = Convert.ToInt32(Maptool.Properties.Resources.GRID_CELL_WIDTH);
        Bitmap bmp = null;
        public main_map.Tile SelectedTile;
        int TileSize = Convert.ToInt32(Maptool.Properties.Resources.TILESIZE);
        private Main mainForm;


        public TileSelectForm(Main form)
        {
            InitializeComponent();
            mainForm = form;
            SelectedTile.tile = new Bitmap(TileSize, TileSize);
        }

        public void changeImage(int idx)
        {
            if (mainForm.TileList.Count == 0)
            {
                this.Size = new Size(300, 500);
                this.ImageLoadPanel.Size = new Size(300, 400);
                bmp = new Bitmap(300, 400);
                this.ImageLoadPanel.Image = bmp;
                this.ImageIndex.Text = "0 / 0";

                index = -1;

                return;
            }

            this.Size = new Size(mainForm.TileList[idx].image.Width + 5, mainForm.TileList[idx].image.Height + 95);
            this.ImageLoadPanel.Location = new Point(0, 64);
            this.ImageLoadPanel.Size = new Size(mainForm.TileList[idx].image.Width, mainForm.TileList[idx].image.Height);
            //this.pictureBox1.Image = mainForm.TileList[idx];

            this.ImageIndex.Text = (idx + 1).ToString() + " / " + mainForm.TileList.Count.ToString();

            index = idx;

            bmp = new Bitmap(mainForm.TileList[idx].image);

            bmp = mainForm.drawGrid(bmp, new Pen(Color.Blue, brush), true, TileSize);

            /*
            Graphics g = Graphics.FromImage(bmp);
            Pen gridPen = new Pen(Color.Blue, brush);
            gridPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDot;

            for (int i = 0; i < bmp.Size.Width / TileSize; ++i)
            {
                for (int j = 0; j < bmp.Size.Height / TileSize; ++j)
                    g.DrawRectangle(gridPen, i * TileSize, j * TileSize, TileSize, TileSize);
            }
            */
            this.ImageLoadPanel.Image = bmp;
            //g.Dispose();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (index > 0)
                changeImage(index-1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (index < mainForm.TileList.Count - 1)
                changeImage(index+1);
        }

        private void TileSelectForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
            ((TileSelectForm)sender).Hide();
        }

        Point highlight = new Point(0, 0);
        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (index == -1) return;
            if (highlight.X == e.X / TileSize && highlight.Y == e.Y / TileSize)
                return;
            

            Bitmap temp = new Bitmap(bmp);
            int HighlightBrush = brush + 2;
            Pen highlightPen = new Pen(Color.Red, HighlightBrush);
            //highlightPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDot;

            Graphics.FromImage(temp).DrawRectangle(highlightPen, (e.X / TileSize) * TileSize + ((HighlightBrush - 1) / 2), (e.Y / TileSize) * TileSize + ((HighlightBrush - 1) / 2), TileSize - (HighlightBrush / 2), TileSize - (HighlightBrush / 2));

            highlight.X = e.X / TileSize;
            highlight.Y = e.Y / TileSize;

            ImageLoadPanel.Image = temp;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (index == -1) return;
            MouseEventArgs Event = (MouseEventArgs)e;

            int x = (Event.X / TileSize) * TileSize;
            int y = (Event.Y / TileSize) * TileSize;

            if (x + TileSize > mainForm.TileList[index].image.Width || y + TileSize > mainForm.TileList[index].image.Height)
                return;

            SelectedTile.isFull = true;
            SelectedTile.attributeMove = true;
            SelectedTile.TileLocation = new Point(x, y);
            SelectedTile.TIleSetID = mainForm.TileList[index].ID;
            SelectedTile.tile = new Bitmap(TileSize, TileSize);
            SelectedTile.tile = mainForm.TileList[index].image.Clone(new Rectangle(new Point(x,y),new Size(TileSize, TileSize)), mainForm.TileList[index].image.PixelFormat);
            Selected.Image = SelectedTile.tile;
        }

        private void OpenTileSet_Click(object sender, EventArgs e)
        {
            System.IO.Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = System.IO.Directory.GetCurrentDirectory();
            openFileDialog1.Filter = "image files (*.png)|*.png|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            mainForm.TileList.Add(new Main.BitmapList(mainForm.bitmapID++, new Bitmap(openFileDialog1.FileName)));
                            mainForm.TileSelectWindow.Show();

                            mainForm.TileSelectWindow.changeImage(mainForm.TileList.Count - 1);
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);
                }
            }
        }

        private void DelTileSet_Click(object sender, EventArgs e)
        {
            int count = mainForm.TileList.Count;
            if (count == 0)
                return;

            for (int i = 0; i < mainForm.mainMap.MapSize.Width; ++i)
            {
                for (int j = 0; j < mainForm.mainMap.MapSize.Height; ++j)
                {
                    if (mainForm.mainMap.grid[i, j].TIleSetID == mainForm.TileList[index].ID)
                    {
                        MessageBox.Show("이 이미지 파일이 사용중이므로 삭제할 수 없습니다. : [" + i.ToString() + "." + j.ToString() + "]");
                        return;
                    }
                }
            }
            mainForm.TileList.RemoveAt(index);
            changeImage(index-1 < 0 ? 0 : index-1);
        }

        Bitmap temp = new Bitmap(64, 64);
        private void SelectEmptyTile_Click(object sender, EventArgs e)
        {
            SelectedTile.isFull = false;
            SelectedTile.tile = temp;
            SelectedTile.attributeMove = false;
            Selected.Image = temp;
        }
    }
}
