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
        // form
        public main_map mainMap;
        public TileSelectForm TileSelectWindow = null;

        // values
        Bitmap minimapImage;
        public double Zoom;
        public int TileSize = Convert.ToInt32(Maptool.Properties.Resources.TILESIZE);
        public main_map._tile SelectedTileInfo;
        public List<Bitmap> TileList = new List<Bitmap>();

        public Bitmap drawGrid(Bitmap image, Pen gridPen, bool isDot, int size)
        {
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
        private void XMLCreate()
        {
            XmlDocument NewXmldoc = new XmlDocument();
            NewXmldoc.AppendChild(NewXmldoc.CreateXmlDeclaration("1.0", "utf-8", "yes"));

            XmlNode root = NewXmldoc.CreateElement("", "Root", "");
            NewXmldoc.AppendChild(root);

            NewXmldoc.Save("test.xml");

        }
        public void Minimap_update()
        {
            if (minimapImage != null)
                minimapImage.Dispose();

            Image img = mainMap.flag;
            minimapImage = new Bitmap(img.Width, img.Height);
            Graphics g = Graphics.FromImage(minimapImage);
            Pen pen = new Pen(Color.Black, 10);

            g.DrawImage(img, 0, 0, minimapImage.Width, minimapImage.Height);
            g.DrawRectangle(pen, new Rectangle(mainMap.HorizontalScroll.Value, mainMap.VerticalScroll.Value, main_map_panel.Width - 30, main_map_panel.Height - 50));

            minimap.Image = minimapImage;
            g.Dispose();
            pen.Dispose();
        }
        public void init()
        {
            XMLCreate();

            layers.SelectedIndex = 0;
            magnification.Text = "100%";
            Zoom = Convert.ToDouble(magnification.Text.Remove(magnification.Text.Length - 1)) / 100;

            TileSelectWindow = new TileSelectForm(this);

            mainMap_init(16, 16);
            Minimap_update();

            //mainMap.Show();
            TileSelectWindow.Show();
        }
        public void mainMap_init(int width, int height)
        {
            mainMap = new main_map(width, height, this);

            mainMap.TopLevel = false;
            this.main_map_panel.Controls.Add(mainMap);

            mainMap.Parent = this.main_map_panel;
            mainMap.Text = "";

            mainMap.ControlBox = false;

            this.Main_Resize(null, null);
            mainMap.SetBounds(0, 0, mainMap.Parent.Size.Width - 30, mainMap.Parent.Size.Height - 50);

            mainMap.Show();
        }
        public Main()
        {
            InitializeComponent();
            init();
            this.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.main_map_Wheel);
        }
        private void main_map_Wheel(object sender, MouseEventArgs e)
        {
            if ((e.Delta / 120) > 0)
                MessageBox.Show(" UP ");
            else
                MessageBox.Show(" DOWN ");

            //((main_map)sender).VerticalScroll.Value += 10;
        }

        private void menu_item_new_Click(object sender, EventArgs e)
        {
            new_map newForm = new new_map(this);
            newForm.Owner = this;
            newForm.Show();
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
            System.IO.Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "XML files (*.xml)|*.XML|CSM Map files|*.CSM|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {

                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);
                }
            }

        }

        private void menu_item_exit_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void Main_Resize(object sender, EventArgs e)
        {
            // main_map resizing
            main_map_panel.Size = new Size(this.Size.Width - this.main_map_panel.Location.X, this.Size.Height - this.main_map_panel.Location.Y - 15);
            mainMap.SetBounds(0, 0, mainMap.Parent.Size.Width - 10, mainMap.Parent.Size.Height - 30);

            // contents resizing
            contents.Size = new Size(contents.Size.Width, Screen.PrimaryScreen.Bounds.Height - minimap.Size.Height);

            // 
            Minimap_update();
        }

        private void magnification_TextChanged(object sender, EventArgs e)
        {
            Zoom = Convert.ToDouble(magnification.Text.Remove(magnification.Text.Length - 1)) / 100;
        }

        private void minimapViewMove(MouseEventArgs e)
        {
            double w = e.X * TileSize / (minimap.Width / mainMap.MapSize.Width);
            double h = e.Y * TileSize / (minimap.Height / mainMap.MapSize.Height);

            if (mainMap.VerticalScroll.Visible)
                mainMap.VerticalScroll.Value = Convert.ToInt32(h);
            if (mainMap.HorizontalScroll.Visible)
                mainMap.HorizontalScroll.Value = Convert.ToInt32(w);

            mainMap.PerformLayout();
            Minimap_update();
        }

        bool isMinimapDrag = false;
        private void minimap_MouseDown(object sender, MouseEventArgs e)
        {
            isMinimapDrag = true;
            minimapViewMove(e);
        }

        private void minimap_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.X <= 0 || e.X >= minimap.Width || e.Y <= 0 || e.Y >= minimap.Height) return;
            if (isMinimapDrag)
                minimapViewMove(e);
        }

        private void minimap_MouseUp(object sender, MouseEventArgs e)
        {
            isMinimapDrag = false;
        }
    }
}
