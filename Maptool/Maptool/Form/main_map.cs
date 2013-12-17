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
        public Tile[,] grid;
        public Point highlight;
        int brush = Convert.ToInt32(Maptool.Properties.Resources.GRID_CELL_WIDTH);
        public Bitmap flag;
        Main mainForm;

        public struct Tile
        {
            public Point TileLocation;
            public int TIleSetID;
            public int Attribute;
            public Bitmap tile;
            public bool isFull;

            public bool attributeMove;
            public int attributeHeight;
        };
        public main_map(int width, int height, Main Form)
        {
            InitializeComponent();

            mainForm = Form;
            MapSize = new Size(width, height);
            grid = new Tile[MapSize.Width, MapSize.Height];
            work_map.Size = new Size(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
            highlight = new Point(0, 0);
            flag = new Bitmap(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
            flag = mainForm.drawGrid(flag, new Pen(Color.Blue, brush), true, TileSize);
            Graphics.FromImage(temp).FillRectangle(new SolidBrush(Color.White), 0, 0, TileSize, TileSize);

            work_map.Image = flag;
        }
        public void refresh()
        {
            flag.Dispose();
            flag = new Bitmap(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
            Graphics g = Graphics.FromImage(flag);

            for (int i = 0; i < MapSize.Width; ++i)
            {
                for (int j = 0; j < MapSize.Height; ++j)
                {
                    if (grid[i, j].isFull)
                        g.DrawImage(grid[i, j].tile, new Point(i * TileSize, j * TileSize));
                    else
                        g.DrawImage(temp, new Point(i * TileSize, j * TileSize));
                }
            }
            mainForm.drawGrid(flag, new Pen(Color.Blue, brush), true, TileSize);

            g.Dispose();

            work_map.Image = flag;
        }
        private void cellClick(MouseEventArgs e)
        {
           if (highlight.X == e.X / TileSize && highlight.Y == e.Y / TileSize)
                return;

            int x = (e.X / TileSize) * TileSize;
            int y = (e.Y / TileSize) * TileSize;

            switch(mainForm.layerType)
            {
                case LAYER_TYPE.TILE_LAYER:

                   grid[x / TileSize, y / TileSize] = returnSelectedTile(grid[x / TileSize, y / TileSize], mainForm.TileSelectWindow.SelectedTile);

                   Graphics g = Graphics.FromImage(flag);
                   g.DrawImage(mainForm.TileSelectWindow.SelectedTile.tile, new Point(x, y));

                   mainForm.updateAttributePanel(x / TileSize, y / TileSize);

                   work_map.Image = flag;
                   mainForm.Minimap_update();
                   refresh();
                   g.Dispose();
                   break;

                case LAYER_TYPE.ATTRIBUTE_LAYER :


                    break;

                case LAYER_TYPE.OBJECT_LAYER :


                    break;

            }
            
        }
        private void GridCellHighlight(object sender, MouseEventArgs e)
        {
            if (highlight.X == e.X / TileSize && highlight.Y == e.Y / TileSize)
                return;

            if (isDrag)
                cellClick(e);

            Bitmap temp = new Bitmap(flag);
            int HighlightBrush = brush + 2;
            Pen highlightPen = new Pen(Color.Red, HighlightBrush);

            Graphics.FromImage(temp).DrawRectangle(highlightPen, (e.X / TileSize) * TileSize + ((HighlightBrush - 1) / 2), (e.Y / TileSize) * TileSize + ((HighlightBrush - 1) / 2), TileSize - (HighlightBrush / 2), TileSize - (HighlightBrush / 2));

            highlight.X = e.X / TileSize;
            highlight.Y = e.Y / TileSize;

            work_map.Image = temp;

            highlightPen.Dispose();
            System.GC.Collect();
            //temp.Dispose();
        }
        private Tile returnSelectedTile(Tile cell, Tile tile)
        {
            tile.attributeHeight = cell.attributeHeight;
            tile.attributeMove = cell.attributeMove;

            return tile;
        }
        private void main_map_Scroll(object sender, ScrollEventArgs e)
        {
            work_map.Image = flag;
            mainForm.Minimap_update();
        }

        Bitmap temp = new Bitmap(64, 64);
        bool isDrag = false;
        private void main_map_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                mainForm.TileSelectWindow.SelectedTile.isFull = false;
                mainForm.TileSelectWindow.SelectedTile.tile = temp;
                mainForm.TileSelectWindow.SelectedTile.attributeMove = false;

                return;
            }
            isDrag = true;
            cellClick(e);
        }

        private void work_map_MouseUp(object sender, MouseEventArgs e)
        {
            isDrag = false;
        }
    }
}
