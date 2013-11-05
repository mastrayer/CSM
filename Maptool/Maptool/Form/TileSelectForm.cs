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

        public TileSelectForm(Main form)
        {
            InitializeComponent();
            mainForm = form;
            SelectedTile.Tile = new Bitmap(TileSize, TileSize);
        }

        public main_map._tile SelectedTile;
        int TileSize = Convert.ToInt32(Maptool.Properties.Resources.TILESIZE);
        private Main mainForm ;

        public void changeImage(int idx)
        {
            if (mainForm.TileList.Count == 0)
            {
                this.Size = new Size(300, 500);
                this.pictureBox1.Size = new Size(300, 400);
                bmp = new Bitmap(300, 400);
                this.pictureBox1.Image = bmp;
                this.label1.Text = "0 / 0";

                index = -1;

                return;
            }
            this.Size = new Size(mainForm.TileList[idx].Width + 5, mainForm.TileList[idx].Height + 95);
            this.pictureBox1.Location = new Point(0, 64);
            this.pictureBox1.Size = new Size(mainForm.TileList[idx].Width, mainForm.TileList[idx].Height);
            //this.pictureBox1.Image = mainForm.TileList[idx];

            this.label1.Text = (idx + 1).ToString() + " / " + mainForm.TileList.Count.ToString();

            index = idx;

            bmp = new Bitmap(mainForm.TileList[idx]);

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
            this.pictureBox1.Image = bmp;
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

            pictureBox1.Image = temp;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (index == -1) return;
            MouseEventArgs Event = (MouseEventArgs)e;
            //MessageBox.Show((Event.X / TileSize).ToString() + "." + (Event.Y / TileSize).ToString());

            int x = (Event.X / TileSize) * TileSize;
            int y = (Event.Y / TileSize) * TileSize;

            SelectedTile.TileLocation = new Point(x, y);
            SelectedTile.TIleSetIndex = index;
            SelectedTile.Tile = new Bitmap(TileSize, TileSize);
            SelectedTile.Tile = mainForm.TileList[index].Clone(new Rectangle(new Point(x,y),new Size(TileSize, TileSize)), mainForm.TileList[index].PixelFormat);
            pictureBox2.Image = SelectedTile.Tile;
        }

        private void OpenTileSet_Click(object sender, EventArgs e)
        {
            System.IO.Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\";
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
                            mainForm.TileList.Add(new Bitmap(openFileDialog1.FileName));
                            mainForm.TileSelectWindow.Show();

                            mainForm.TileSelectWindow.changeImage(mainForm.TileList.Count - 1);


                            //pictureBox1.Image = TileList[TileList.Count-1];
                            //                             Image image = Image.FromFile(openFile.FileName);
                            // 
                            //                             // Image 클래스뿐아니라위에서상속된클래스로도
                            // 
                            //                             // 이미지를보여줄수있다
                            // 
                            //                             Bitmap image = new Bitmap(openFile.FileName);
                            // 
                            //                             //Image image = Image.FromStream(stream);
                            // 
                            //                             // 여기서은이미지정보가포함된스트림이다
                            // 
                            //                             picbox_main.Image = image;
                            //                             // Insert code to read the stream here.
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

            mainForm.TileList.RemoveAt(index);
            changeImage(0);
        }
    }
}
