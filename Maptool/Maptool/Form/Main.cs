using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Xml;
using System.Collections.Specialized;


namespace Maptool
{
    public partial class Main : Form
    {
        private void XMLCreate()
        {
            XmlDocument NewXmldoc = new XmlDocument();
            NewXmldoc.AppendChild(NewXmldoc.CreateXmlDeclaration("1.0", "utf-8", "yes"));

            XmlNode root = NewXmldoc.CreateElement("", "Root", "");
            NewXmldoc.AppendChild(root);

            NewXmldoc.Save("test.xml");

        }
        //CMap main_map;

        static class DEFINE
        {
            public const int TILE_SIZE = 30;
        }
        public main_map._tile SelectedTileInfo;
        public List<Bitmap> TileList = new List<Bitmap>();
        public TileSelectForm TileSelectWindow = null;
        public double Zoom;

        public Bitmap drawGrid(Bitmap image, Pen gridPen, bool isDot, int size)
        {
//             flag = new Bitmap(MapSize.Width * TileSize + brush, MapSize.Height * TileSize + brush);
//             Graphics flagGraphics = Graphics.FromImage(flag);
//             Pen gridPen = new Pen(Color.Blue, brush);
//             gridPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDot;
// 
//             for (int i = 0; i < MapSize.Width; ++i)
//             {
//                 for (int j = 0; j < MapSize.Height; ++j)
//                 {
//                     flagGraphics.DrawRectangle(gridPen, i * TileSize, j * TileSize, TileSize, TileSize);
//                 }
//             }
//             work_map.Image = flag;

            Graphics g = Graphics.FromImage(image);
            if (isDot == true)
                gridPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDot;

            for (int i = 0; i < image.Width / size; ++i)
            {
                for (int j = 0; j < image.Height / size; ++j)
                    g.DrawRectangle(gridPen, i * size, j * size, size, size);
            }

            g.Dispose();
            return image;
         }

        /*
        public class CMap
        {
            private Size Map_size;
            private int[,] Map;

            public CMap(int h, int w)
            {
                Init(h,w);
            }
            public Size size
            {
                get { return this.Map_size; }
                set { Map_size = value; }
            }
            public int[,] map
            {
                get { return this.Map; }
                set { this.Map = value; }
            }
            public void Init(int h, int w)
            {
                this.Map_size.Height = h;
                this.Map_size.Width = w;
                Map = new int[h, w];
                Map.Initialize();
            }
        }*/

        public void Minimap_init()
        {
            Bitmap flag = new Bitmap(200, 200);
            Graphics flagGraphics = Graphics.FromImage(flag);

            for (int i = 0; i < 200; i++)
            {

                for (int j = i % 2; j < 200; j += 2)
                {
                    flagGraphics.FillRectangle(Brushes.Yellow, i, j, 1, 1);
                    flagGraphics.FillRectangle(Brushes.Red, i, j - (j % 2), 1, 1);
                }
            }
            minimap.Image = flag;
        }/*
        public void map_init()
        {
            //Bitmap flag = new Bitmap(map.Size.Width, map.Size.Height);
            Bitmap flag = new Bitmap(main_map.size.Width * DEFINE.TILE_SIZE, main_map.size.Height * DEFINE.TILE_SIZE);
            Graphics flagGraphics = Graphics.FromImage(flag);

            flagGraphics.FillRectangle(Brushes.White, 0, 0, map.Size.Width, map.Size.Height);

            Pen rec_color = new Pen(Color.Black, 2);

            for( int i = 0 ; i < main_map.size.Width ; ++i)
            {
                for (int j = 0; j < main_map.size.Height; ++j)
                    flagGraphics.DrawRectangle(rec_color, i*DEFINE.TILE_SIZE, j*DEFINE.TILE_SIZE, DEFINE.TILE_SIZE, DEFINE.TILE_SIZE);
            }
            

//             for (int i = 0; i < map_size.Height; i++)
//                flagGraphics.FillRectangle(Brushes.Black, 0, i * DEFINE.TILE_SIZE, map_size.Width * DEFINE.TILE_SIZE, 1);
// 
//             for (int i = 0; i < map_size.Width; i++)
//                flagGraphics.FillRectangle(Brushes.Black, i * DEFINE.TILE_SIZE, 0 , 1, map_size.Height * DEFINE.TILE_SIZE);

            map.Image = flag;
        }*/
        main_map c_Form;
        public void init()
        {
            XMLCreate();
            //main_map = new CMap(16, 16);

            //main_map c_Form = new main_map();

            magnification.Text = "100%";
            Zoom = Convert.ToDouble(magnification.Text.Remove(magnification.Text.Length-1)) / 100;

            TileSelectWindow = new TileSelectForm(this);
            c_Form = new main_map(this);

            c_Form.TopLevel = false;
            this.main_map_panel.Controls.Add(c_Form);

            c_Form.Parent = this.main_map_panel;
            c_Form.Text = "";

            c_Form.ControlBox = false;

            main_map_panel.Size = new Size(this.Size.Width - this.main_map_panel.Location.X, this.Size.Height - this.main_map_panel.Location.Y);
            c_Form.SetBounds(0, 0, c_Form.Parent.Size.Width - 30, c_Form.Parent.Size.Height - 50);

            c_Form.Show();
            TileSelectWindow.Show();
            //TileSelectWindow.Location = new Point(this.Location.X, this.Location.Y);

            Minimap_init();

        }
        public Main()
        {
            InitializeComponent();

            init();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            layers.SelectedIndex = 0;
        }

        private void menu_item_new_Click(object sender, EventArgs e)
        {
            new_map test = new new_map();
            test.Owner = this;
            test.Show();

        }

        private void menu_item_save_Click(object sender, EventArgs e)
        {
            System.IO.Stream myStream;
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if ((myStream = saveFileDialog1.OpenFile()) != null)
                {
                    // Code to write the stream goes here.
                    myStream.Close();
                }
            }

        }

        private void menu_item_open_Click(object sender, EventArgs e)
        {
            /*
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
                            TileList.Add(new Bitmap(openFileDialog1.FileName));
                            TileSelectWindow.Show();

                            TileSelectWindow.changeImage(TileList.Count - 1);


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
            */

        }

        private void menu_item_exit_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void Main_Resize(object sender, EventArgs e)
        {
            // map resizing
            //panel1.SetBounds(main_map_panel.Location.X, main_map_panel.Location.Y, Screen.PrimaryScreen.Bounds.Width - minimap.Size.Width, Screen.PrimaryScreen.Bounds.Height - minimap.Size.Height);

            //panel1.Size = new Size(this.Size.Width - this.panel1.Location.X - 10 , this.Size.Height - this.panel1.Location.Y - 30 );
            main_map_panel.Size = new Size(this.Size.Width - this.main_map_panel.Location.X, this.Size.Height - this.main_map_panel.Location.Y);
            c_Form.SetBounds(0, 0, c_Form.Parent.Size.Width - 10, c_Form.Parent.Size.Height - 30);
            //c_Form.work_map.Size = new Size(c_Form.Parent.Width, c_Form.Parent.Height);

            //label1.Text = this.Size.Width + "/" + this.Size.Height + "..." + (this.Size.Width - this.panel1.Location.X).ToString() + " /" + (this.Size.Height - this.panel1.Location.Y).ToString();
            //c_Form.Size = new Size(Screen.PrimaryScreen.Bounds.Width - minimap.Size.Width, Screen.PrimaryScreen.Bounds.Height - minimap.Size.Height);
            //c_Form.SetBounds(0, 0, c_Form.Parent.Size.Width, c_Form.Parent.Size.Height);

            // contents resizing
            //contents.Size = new Size(contents.Size.Width, Screen.PrimaryScreen.Bounds.Height - minimap.Size.Height);
        }

        private void magnification_TextChanged(object sender, EventArgs e)
        {
            Zoom = Convert.ToDouble(magnification.Text.Remove(magnification.Text.Length - 1)) / 100;
        }
    }
}
