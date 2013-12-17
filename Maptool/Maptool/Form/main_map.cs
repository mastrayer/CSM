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
        public bool SelectMode = false;
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
            public ObjectType type;
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
                    {
                        Point DrawPoint = new Point(i * TileSize, j * TileSize);
                        g.DrawImage(grid[i, j].tile, DrawPoint);

                        switch (grid[i, j].type)
                        {
                            case ObjectType.TILE:
                                break;
                            case ObjectType.STARTING_POINT:
                                g.DrawImage(Properties.Resources.StartingPoint, DrawPoint);
                                break;
                            case ObjectType.CROWN:
                                g.DrawImage(Properties.Resources.Crown, DrawPoint);
                                break;
                            case ObjectType.BARRACK:
                                g.DrawImage(Properties.Resources.Barrack, DrawPoint);
                                break;
                        }

                        if(grid[i,j].attributeMove == true)
                            g.DrawImage(Properties.Resources.Move, DrawPoint);

                    }else
                        g.DrawImage(temp, new Point(i * TileSize, j * TileSize));
                }
            }
            mainForm.drawGrid(flag, new Pen(Color.Blue, brush), true, TileSize);

            g.Dispose();

            work_map.Image = flag;
        }
        private void cellClick(MouseEventArgs e)
        {
            int x = (e.X / TileSize) * TileSize;
            int y = (e.Y / TileSize) * TileSize;

            if(SelectMode == true)
            {
                mainForm.updateAttributePanel(e.X / TileSize, e.Y / TileSize);
                return;
            }
                
            switch(mainForm.layerType)
            {
                case LAYER_TYPE.TILE_LAYER:

                   //grid[x / TileSize, y / TileSize] = returnSelectedTile(ref grid[x / TileSize, y / TileSize], mainForm.TileSelectWindow.SelectedTile);
                   returnSelectedTile(ref grid[x / TileSize, y / TileSize], mainForm.TileSelectWindow.SelectedTile);

                   Graphics g = Graphics.FromImage(flag);
                   g.DrawImage(mainForm.TileSelectWindow.SelectedTile.tile, new Point(x, y));

                   work_map.Image = flag;
                   mainForm.Minimap_update();
                   g.Dispose();
                   break;

                case LAYER_TYPE.ATTRIBUTE_LAYER :
                   if (grid[x / TileSize, y / TileSize].isFull == true)
                   {
                       grid[x / TileSize, y / TileSize].attributeHeight = mainForm.attributeSettingWindow.height;
                       grid[x / TileSize, y / TileSize].attributeMove = mainForm.attributeSettingWindow.move;
                   }
                   break;

                case LAYER_TYPE.OBJECT_LAYER :
                   if (grid[x / TileSize, y / TileSize].isFull == true)
                        grid[x / TileSize, y / TileSize].type = mainForm.type;
                   break;

            }
            mainForm.updateAttributePanel(e.X / TileSize, e.Y / TileSize);
            refresh();
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
        private void returnSelectedTile(ref Tile cell, Tile tile)
        {
            cell.TileLocation = tile.TileLocation;
            cell.isFull = tile.isFull;
            cell.tile = tile.tile;
            cell.TileLocation = tile.TileLocation;
            cell.TIleSetID = tile.TIleSetID;
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
            if (SelectMode == false) this.Cursor = Cursors.Default;

            if(e.Button == MouseButtons.Left)
            {
                cellClick(e);
                isDrag = true;
            }else if (e.Button == MouseButtons.Right)
            {
                if(SelectMode == false)
                    this.Cursor = Cursors.Help;
                else
                    this.Cursor = Cursors.Default;

                SelectMode = !SelectMode;
                return;
            }
            
        }

        private void work_map_MouseUp(object sender, MouseEventArgs e)
        {
            isDrag = false;
        }
    }
}
