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
    public partial class main_map : Form
    {
        public int TileSize = Convert.ToInt32(Maptool.Properties.Resources.TILESIZE);
        public Size MapSize;
        public _tile[,] grid;
        public Point highlight;
        int brush = Convert.ToInt32(Maptool.Properties.Resources.GRID_CELL_WIDTH);
        public Bitmap flag;
        Main mainForm;

        public struct _tile
        {
            public Point TileLocation;
            public int TIleSetIndex;
            public int Attribute;
            public Bitmap Tile;
        };
        public main_map(int width, int height, Main Form)
        {
            InitializeComponent();

            mainForm = Form;
            MapSize = new Size(width, height);
            grid = new _tile[MapSize.Width, MapSize.Height];
            work_map.Size = new Size(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
            highlight = new Point(0, 0);
            flag = new Bitmap(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
            flag = mainForm.drawGrid(flag, new Pen(Color.Blue, brush), true, TileSize);

            work_map.Image = flag;
        }
        private void GridCellHighlight(object sender, MouseEventArgs e)
        {
            if (highlight.X == e.X / TileSize && highlight.Y == e.Y / TileSize)
                return;

            Bitmap temp = new Bitmap(flag);
            int HighlightBrush = brush + 2;
            Pen highlightPen = new Pen(Color.Red, HighlightBrush);

            Graphics.FromImage(temp).DrawRectangle(highlightPen, (e.X / TileSize) * TileSize + ((HighlightBrush - 1) / 2), (e.Y / TileSize) * TileSize + ((HighlightBrush - 1) / 2), TileSize - (HighlightBrush / 2), TileSize - (HighlightBrush / 2));

            highlight.X = e.X / TileSize;
            highlight.Y = e.Y / TileSize;

            work_map.Image = temp;

            highlightPen.Dispose();
            //temp.Dispose();
        }

        private void GridCellClick(object sender, EventArgs e)
        {
            MouseEventArgs Event = (MouseEventArgs)e;

            int x = (Event.X / TileSize) * TileSize;
            int y = (Event.Y / TileSize) * TileSize;

            Graphics g = Graphics.FromImage(flag);
            g.DrawImage(mainForm.TileSelectWindow.SelectedTile.Tile, new Point(x, y));

            work_map.Image = flag;
            mainForm.Minimap_update();

            g.Dispose();
        }

        private void main_map_Scroll(object sender, ScrollEventArgs e)
        {
            work_map.Image = flag;
            mainForm.Minimap_update();
        }

        private void main_map_Wheel(object sender, MouseEventArgs e)
        {
            if ((e.Delta / 120) > 0)
                MessageBox.Show(" UP ");
            else
                MessageBox.Show(" DOWN ");

            ((main_map)sender).VerticalScroll.Value += 10;
        }
    }
}
