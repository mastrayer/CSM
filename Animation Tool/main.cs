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

        List<Bitmap> originalSprites = new List<Bitmap>();
        List<PictureBox> sprites = new List<PictureBox>();
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

                    originalSprites.Add(new Bitmap(filename));

                    sprites.Add(a);
                    a.Click += new System.EventHandler(this.sprite_Click);
                    a.DoubleClick += new System.EventHandler(this.sprite_DoubleClick);
                    spritePanel.Controls.Add(a);
                }
                updateImageList();                
            }
        }
        private void updateImageList()
        {
            if (sprites.Count == 0)
            {
                selectedSprite = 0;
                return;
            }

            int totalHeight = 0;
            int spriteWidth = splitContainer1.Panel1.Width - 30;//spritePanel.Width;
            int spriteGap = 10;
            Graphics g = null;

            for (int i=0; i<sprites.Count; ++i)
            {
                int spriteHeight = (int)((double)originalSprites[i].Size.Height / (double)originalSprites[i].Size.Width * (double)spriteWidth);
                if (sprites[i].Image != null)
                    sprites[i].Image.Dispose();

                sprites[i].Image = new Bitmap(spriteWidth, spriteHeight);
                g = Graphics.FromImage(sprites[i].Image);
                
                sprites[i].Size = new Size(spriteWidth, spriteHeight); // temp[i].Image.Size;
                sprites[i].Location = new Point(0, totalHeight);// i == 0 ? new Point(0, 0) : new Point(0, temp[i - 1].Bottom + spriteGap);
                g.DrawImage(originalSprites[i], new Rectangle(0, 0, spriteWidth, spriteHeight));
                totalHeight += spriteHeight + spriteGap;
            }

            Graphics.FromImage(sprites[selectedSprite].Image).DrawRectangle(new Pen(Color.Red, 8), new Rectangle(0, 0, sprites[selectedSprite].Image.Width, sprites[selectedSprite].Image.Height));
            spritePanel.Height = totalHeight;
            if(g != null)
                g.Dispose();
        }

        private void ButtonSpriteDelete_Click(object sender, EventArgs e)
        {
            if (sprites.Count == 0) return;

            originalSprites[selectedSprite].Dispose();
            sprites[selectedSprite].Dispose();
            originalSprites.RemoveAt(selectedSprite);
            sprites.RemoveAt(selectedSprite);

            if (sprites.Count <= selectedSprite) --selectedSprite;

            updateImageList();
        }

        private void sprite_Click(object sender, EventArgs e)
        {
            PictureBox a = (PictureBox)sender;
            selectedSprite = sprites.FindIndex(delegate(PictureBox s)
            {
                return s.GetHashCode() == a.GetHashCode();
            });
            updateImageList();
        }

        private void sprite_DoubleClick(object sender, EventArgs e)
        {
            MessageBox.Show("DoubleClick");
        }
        private void splitContainer1_SplitterMoved(object sender, SplitterEventArgs e)
        {
            updateImageList();
        }
    }
}
