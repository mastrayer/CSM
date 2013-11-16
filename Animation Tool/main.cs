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
        Bitmap imageList;

        private void ButtonSpriteAdd_Click(object sender, EventArgs e)
        {
            OpenFileDialog openImage = new OpenFileDialog();

            openImage.Filter = "Image Files(*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png";
            openImage.FilterIndex = 1;
            openImage.RestoreDirectory = true;
            openImage.InitialDirectory = System.IO.Directory.GetCurrentDirectory();

            if (openImage.ShowDialog() == DialogResult.OK)
            {
                sprites.Add(new Bitmap(openImage.FileName));
                updateImageList();
            }
        }
        private void updateImageList()
        {
            int upGap = 5;
            int leftGap = 0;
            int spriteGap = 10;
            int spriteWidth = this.LoadedSprite.Size.Width;
            int totalHeight = upGap;
            int p = upGap;

            if (imageList != null) imageList.Dispose();


            foreach (Bitmap image in sprites)
                totalHeight += (int)((double)image.Size.Height / (double)image.Size.Width * (double)spriteWidth + spriteGap);

            imageList = new Bitmap(spriteWidth, totalHeight);
            Graphics g = Graphics.FromImage(imageList);

            foreach (Bitmap image in sprites)
            {
                g.DrawImage(image, new Rectangle(leftGap, p, spriteWidth, (int)((double)image.Size.Height / (double)image.Size.Width * (double)spriteWidth)));
                p += (int)((double)image.Size.Height / (double)image.Size.Width * (double)spriteWidth) + spriteGap;
            }

            LoadedSprite.Image = imageList;
            LoadedSprite.Size = new Size(LoadedSprite.Size.Width, totalHeight);
            g.Dispose();
        }
    }
}
