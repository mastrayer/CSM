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
        public int TileSize = 64;
        public Size MapSize;
        public _tile[,] grid;
        public Point highlight;
        int brush = Convert.ToInt32(Maptool.Properties.Resources.GRID_CELL_WIDTH);
        Main mainForm;

        public struct _tile
        {
            public Point TileLocation;
            public int TIleSetIndex;
            public int Attribute;
            public Bitmap Tile;
        };
        public main_map(Main Form)
        {
            InitializeComponent();

            mainForm = Form;
            MapSize = new Size(16, 16);
            grid = new _tile[MapSize.Width, MapSize.Height];
            work_map.Size = new Size(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
            highlight = new Point(0, 0);

            /*
            Bitmap flag = new Bitmap(30, 30);
            Graphics flagGraphics = Graphics.FromImage(flag);

            flagGraphics.DrawRectangle(new Pen(Color.Black, 2), 0, 0, 30, 30);



            for (int i = 0; i < 10; ++i)
            {
                test[i] = new GridCell();
                test[i].Location = new Point(i * 30, 0);
                test[i].BackColor = Color.White;
                test[i].Size = new Size(30, 30);
                test[i].Image = flag;

                //test[i].Click += new System.EventHandler(this.Click);
                test[i].MouseLeave += new System.EventHandler(this.MouseLeave1);
                //test[i].MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
                test[i].MouseEnter += new System.EventHandler(this.pictureBox1_MouseEnter);

                this.Controls.Add(test[i]);
            }*/
        }
        /*
        private void MouseLeave1(object sender, EventArgs e)
        {
            GridCell temp = (GridCell)sender;
            temp.highlight = false;
            //temp.BackColor = Color.White;
            temp.BorderStyle = BorderStyle.FixedSingle;
        }

        private void Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
             PictureBox temp = (PictureBox)sender;
             temp.BorderStyle = BorderStyle.Fixed3D; 
        }

        private void pictureBox1_MouseEnter(object sender, EventArgs e)
        {
//             for (int i = 0; i < 10; ++i)
//             {
//                 //test[i].BorderStyle = BorderStyle.FixedSingle;
//                 if (!test[i].Capture)
//                 {
//                     test[i].BorderStyle = BorderStyle.FixedSingle;
//                     MessageBox.Show(i.ToString());
//                 }
//             }

            GridCell temp = (GridCell)sender;
            //if (!temp.Capture)
            {
                temp.highlight = true;
                //temp.BackColor = Color.Blue;
                temp.BorderStyle = BorderStyle.Fixed3D;
            }
        }*/

        private void GridCellHighlight(object sender, MouseEventArgs e)
        {
            if (highlight.X == e.X / TileSize && highlight.Y == e.Y / TileSize)
                return;

            Bitmap temp = new Bitmap(flag);
            int HighlightBrush = brush + 2;
            Pen highlightPen = new Pen(Color.Red, HighlightBrush);
            //highlightPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDot;

            Graphics.FromImage(temp).DrawRectangle(highlightPen, (e.X / TileSize) * TileSize + ((HighlightBrush - 1) / 2), (e.Y / TileSize) * TileSize + ((HighlightBrush - 1) / 2), TileSize - (HighlightBrush / 2), TileSize - (HighlightBrush / 2));

            //Graphics.FromImage(flag).DrawRectangle(new Pen(Color.White, HighlightBrush), highlight.X  * TileSize + HighlightBrush, highlight.Y * TileSize + HighlightBrush, TileSize - HighlightBrush*2, TileSize - HighlightBrush*2);
            //Graphics.FromImage(flag).DrawRectangle(new Pen(Color.Red, HighlightBrush), (e.X / TileSize) * TileSize + (HighlightBrush / 2), (e.Y / TileSize) * TileSize + (HighlightBrush / 2), TileSize - HighlightBrush, TileSize - HighlightBrush);


//             Graphics.FromImage(flag).FillRectangle(new SolidBrush(Color.White), highlight.X * TileSize, highlight.Y * TileSize, TileSize, TileSize);
//             Graphics.FromImage(flag).DrawRectangle(new Pen(Color.Black, brush), highlight.X * TileSize, highlight.Y * TileSize, TileSize, TileSize);
//             Graphics.FromImage(flag).DrawRectangle(new Pen(Color.Red, HighlightBrush), (e.X / TileSize) * TileSize + ((HighlightBrush - 1) / 2), (e.Y / TileSize) * TileSize + ((HighlightBrush - 1) / 2) , TileSize - (HighlightBrush / 2), TileSize - (HighlightBrush / 2));

            highlight.X = e.X / TileSize;
            highlight.Y = e.Y / TileSize;

            work_map.Image = temp;

            this.label1.Text = e.X + ":" + e.Y ;
        }

        private void GridCellClick(object sender, EventArgs e)
        {
            MouseEventArgs Event = (MouseEventArgs)e;
            //MessageBox.Show((Event.X / TileSize).ToString() + "." + (Event.Y / TileSize).ToString());

            int x = (Event.X / TileSize) * TileSize;
            int y = (Event.Y / TileSize) * TileSize;


            //Bitmap tttt = new Bitmap(flag);
            Graphics aaa = Graphics.FromImage(flag);
            aaa.DrawImage(mainForm.TileSelectWindow.SelectedTile.Tile, new Point(x, y));

            work_map.Image = flag;
        }

        Bitmap flag;
        private void main_map_Load(object sender, EventArgs e)
        {
            flag = new Bitmap(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
            flag = mainForm.drawGrid(flag, new Pen(Color.Blue, brush), true, TileSize);

            /*
            Graphics flagGraphics = Graphics.FromImage(flag);
            Pen gridPen = new Pen(Color.Blue, brush);
            gridPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDot;

            for (int i = 0; i < MapSize.Width; ++i)
            {
                for (int j = 0; j < MapSize.Height ; ++j)
                {
                    flagGraphics.DrawRectangle(gridPen, i * TileSize, j * TileSize, TileSize, TileSize);
                }
            }
            */
            work_map.Image = flag;
        }
    }/*
    public class GridCell : PictureBox
    {
        private bool m_highlight;
        public GridCell()
        {
            m_highlight = false;
        }
        public bool highlight
        {
            get { return this.m_highlight; }
            set { this.m_highlight = value; }
        }
    }*/
}
