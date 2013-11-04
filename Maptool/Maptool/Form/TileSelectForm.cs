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
        public int index = 0;
        int brush = Convert.ToInt32(Maptool.Properties.Resources.GRID_CELL_WIDTH);
        Bitmap bmp;

        public TileSelectForm(Main form)
        {
            InitializeComponent();
            mainForm = form;
            SelectedTile.Tile = new Bitmap(TileSize, TileSize);
        }

        public main_map._tile SelectedTile;
        int TileSize = Convert.ToInt32(Maptool.Properties.Resources.TILESIZE);
        private Main mainForm = null;

        public void changeImage(int idx)
        {
            this.Size = new Size(mainForm.TileList[idx].Width + 5, mainForm.TileList[idx].Height + 95);
            this.pictureBox1.Location = new Point(0, 64);
            this.pictureBox1.Size = new Size(mainForm.TileList[idx].Width, mainForm.TileList[idx].Height);
            //this.pictureBox1.Image = mainForm.TileList[idx];

            this.label1.Text = (idx + 1).ToString() + " / " + mainForm.TileList.Count.ToString();

            index = idx;

            bmp = new Bitmap(mainForm.TileList[idx]);
            Graphics g = Graphics.FromImage(bmp);
            for (int i = 0; i < bmp.Size.Width / TileSize; ++i)
            {
                for (int j = 0; j < bmp.Size.Height / TileSize; ++j)
                    g.DrawRectangle(new Pen(Color.White, 2), i * TileSize, j * TileSize, TileSize, TileSize);
            }

            this.pictureBox1.Image = bmp;
            g.Dispose();
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
            if (highlight.X == e.X / TileSize && highlight.Y == e.Y / TileSize)
                return;

            Bitmap temp = new Bitmap(bmp);
            int HighlightBrush = brush + 2;
            Graphics.FromImage(temp).DrawRectangle(new Pen(Color.Red, HighlightBrush), (e.X / TileSize) * TileSize + ((HighlightBrush - 1) / 2), (e.Y / TileSize) * TileSize + ((HighlightBrush - 1) / 2), TileSize - (HighlightBrush / 2), TileSize - (HighlightBrush / 2));

            highlight.X = e.X / TileSize;
            highlight.Y = e.Y / TileSize;

            pictureBox1.Image = temp;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
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
    }
}
