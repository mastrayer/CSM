﻿using System;
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

            workSpace.Width = 1000;
            workSpace.Height = 1000;
            workSpace.Controls.Add(frameImage);
            updateWorkSpace();
        }

        List<Bitmap> originalSprites = new List<Bitmap>();
        List<PictureBox> sprites = new List<PictureBox>();
        PictureBox frameImage = new PictureBox();
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
                
                sprites[i].Size = new Size(spriteWidth, spriteHeight);
                sprites[i].Location = new Point(0, totalHeight);
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
            //MessageBox.Show("DoubleClick");


            frameImage.Image = originalSprites[selectedSprite];
            frameImage.Size = originalSprites[selectedSprite].Size;
            frameImage.Location = new Point(workSpace.Width / 2, workSpace.Height / 2);
        }
        private void splitContainer1_SplitterMoved(object sender, SplitterEventArgs e)
        {
            updateImageList();
            updateWorkSpace();
            //Graphics.FromImage(originalSprites[0]).Clear()
        }

        private void updateWorkSpace()
        {
            workSpace.Location = new Point((splitContainer1.Panel2.Right + splitContainer1.Panel2.Left) / 2 - splitContainer1.Panel2.Left - workSpace.Size.Width / 2, (splitContainer1.Panel2.Bottom + splitContainer1.Panel2.Top) / 2 - splitContainer1.Panel2.Top - workSpace.Size.Height / 2);

             label4.Text = splitContainer1.Panel2.Top.ToString();
             label5.Text = splitContainer1.Panel2.Bottom.ToString();
             label6.Text = splitContainer1.Panel2.Left.ToString();
             label7.Text = splitContainer1.Panel2.Right.ToString();
             label8.Text = workSpace.Location.X.ToString();
             label9.Text = workSpace.Location.Y.ToString();
            
            if (workSpace.Image != null)
                workSpace.Image.Dispose();
            workSpace.Image = new Bitmap(workSpace.Size.Width, workSpace.Size.Height);

            Graphics g = Graphics.FromImage(workSpace.Image);
            Pen pen = new Pen(Color.Black, 1);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dot;

            g.DrawLine(pen , 0, workSpace.Size.Height / 2, workSpace.Size.Width, workSpace.Size.Height / 2);
            g.DrawLine(pen , workSpace.Size.Width / 2, 0, workSpace.Size.Width / 2, workSpace.Size.Height);
            g.FillRectangle(new SolidBrush(Color.Blue), workSpace.Size.Height / 2 -1 , workSpace.Size.Width / 2-1 , 3 , 3);

            g.Dispose();

        }
    }
}
