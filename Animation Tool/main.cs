using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Animation_Tool
{
    public partial class main : Form
    {
        public main()
        {            
            InitializeComponent();
        }

        List<Bitmap> sprites = new List<Bitmap>();
        List<PictureBox> temp = new List<PictureBox>();
        int selectedSprite = 0;

        private void ButtonSpriteAdd_Click(object sender, EventArgs e)
        {
            OpenFileDialog openImage = new OpenFileDialog();

            openImage.Filter = "Image Files(*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png";
            openImage.FilterIndex = 1;
            openImage.RestoreDirectory = true;
            openImage.Multiselect = true;
            openImage.InitialDirectory = System.IO.Directory.GetCurrentDirectory();
            
            if (openImage.ShowDialog() == DialogResult.OK)
            {
                foreach (string filename in openImage.FileNames)
                {
                    PictureBox a = new PictureBox();

                    sprites.Add(new Bitmap(filename));
                    //a.Image = sprites[sprites.Count-1];

                    temp.Add(a);
                    a.Click += new System.EventHandler(this.LoadedSprite_Click);
                    a.DoubleClick += new System.EventHandler(this.LoadedSprite_DoubleClick);
                    spritePanel.Controls.Add(a);
                }
                updateImageList();                
            }
        }
        private void updateImageList()
        {
            int totalHeight = 0;
            int spriteWidth = splitContainer1.Panel1.Width - 30;//spritePanel.Width;
            int spriteGap = 10;
            Graphics g = null;

            for (int i=0; i<temp.Count; ++i)
            {
                int spriteHeight = (int)((double)sprites[i].Size.Height / (double)sprites[i].Size.Width * (double)spriteWidth);
                if (temp[i].Image != null)
                    temp[i].Image.Dispose();

                temp[i].Image = new Bitmap(spriteWidth, spriteHeight);
                g = Graphics.FromImage(temp[i].Image);
                
                temp[i].Size = new Size(spriteWidth, spriteHeight); // temp[i].Image.Size;
                temp[i].Location = new Point(0, totalHeight);// i == 0 ? new Point(0, 0) : new Point(0, temp[i - 1].Bottom + spriteGap);
                g.DrawImage(sprites[i], new Rectangle(0, 0, spriteWidth, spriteHeight));
                totalHeight += spriteHeight + spriteGap;
            }

            spritePanel.Height = totalHeight;
            if(g != null)
                g.Dispose();
        }

        private void ButtonSpriteDelete_Click(object sender, EventArgs e)
        {
            if (temp.Count == 0) return;

            sprites[selectedSprite].Dispose();
            temp[selectedSprite].Dispose();
            sprites.RemoveAt(selectedSprite);
            temp.RemoveAt(selectedSprite);

            updateImageList();
        }

        private void LoadedSprite_Click(object sender, EventArgs e)
        {
            PictureBox a = (PictureBox)sender;
            updateImageList();
            Graphics.FromImage(a.Image).DrawRectangle(new Pen(Color.Red, 8), new Rectangle(0, 0, a.Image.Width, a.Image.Height));

            selectedSprite = temp.FindIndex(delegate(PictureBox s)
            {
                return s.GetHashCode() == a.GetHashCode();
            });
        }

        private void LoadedSprite_DoubleClick(object sender, EventArgs e)
        {
            MessageBox.Show("DoubleClick");
        }
    }
}
