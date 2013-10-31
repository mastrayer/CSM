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
    public partial class Main : Form
    {
        //PictureBox pictureBox2 = new PictureBox();
        public void CreateBitmapAtRuntime()
        {
            Bitmap flag = new Bitmap(200, 200);
            Graphics flagGraphics = Graphics.FromImage(flag);

            for (int i = 0; i < 200; i++)
            {
                for (int j = i % 2; j < 200; j += 2)
                {
                    flagGraphics.FillRectangle(Brushes.Yellow, i, j, 1, 1);
                    flagGraphics.FillRectangle(Brushes.Red, i, j-(j%2), 1, 1);
                }
            }
            minimap.Image = flag;
        }

        public Main()
        {
            InitializeComponent();

            CreateBitmapAtRuntime();
            
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
            System.IO.Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
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
                            // Insert code to read the stream here.
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
            // map resizing
            map.Size = new Size(Screen.PrimaryScreen.Bounds.Width - minimap.Size.Width, Screen.PrimaryScreen.Bounds.Height - minimap.Size.Height);

            // contants resizing
            contants.Size = new Size(contants.Size.Width, Screen.PrimaryScreen.Bounds.Height - minimap.Size.Height);

            
        }

    }
}
