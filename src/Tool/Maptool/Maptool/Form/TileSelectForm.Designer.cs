namespace Maptool
{
    partial class TileSelectForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Prev = new System.Windows.Forms.Button();
            this.Next = new System.Windows.Forms.Button();
            this.ImageIndex = new System.Windows.Forms.Label();
            this.ImageLoadPanel = new System.Windows.Forms.PictureBox();
            this.Selected = new System.Windows.Forms.PictureBox();
            this.OpenTileSet = new System.Windows.Forms.Button();
            this.DelTileSet = new System.Windows.Forms.Button();
            this.SelectEmptyTile = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.ImageLoadPanel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Selected)).BeginInit();
            this.SuspendLayout();
            // 
            // Prev
            // 
            this.Prev.Location = new System.Drawing.Point(68, 5);
            this.Prev.Name = "Prev";
            this.Prev.Size = new System.Drawing.Size(20, 20);
            this.Prev.TabIndex = 0;
            this.Prev.Text = "<<";
            this.Prev.UseVisualStyleBackColor = true;
            this.Prev.Click += new System.EventHandler(this.button1_Click);
            // 
            // Next
            // 
            this.Next.Location = new System.Drawing.Point(138, 5);
            this.Next.Name = "Next";
            this.Next.Size = new System.Drawing.Size(20, 20);
            this.Next.TabIndex = 1;
            this.Next.Text = ">";
            this.Next.UseVisualStyleBackColor = true;
            this.Next.Click += new System.EventHandler(this.button2_Click);
            // 
            // ImageIndex
            // 
            this.ImageIndex.AutoSize = true;
            this.ImageIndex.Location = new System.Drawing.Point(97, 10);
            this.ImageIndex.Name = "ImageIndex";
            this.ImageIndex.Size = new System.Drawing.Size(31, 12);
            this.ImageIndex.TabIndex = 2;
            this.ImageIndex.Text = "0 / 0";
            // 
            // ImageLoadPanel
            // 
            this.ImageLoadPanel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.ImageLoadPanel.Location = new System.Drawing.Point(0, 68);
            this.ImageLoadPanel.Name = "ImageLoadPanel";
            this.ImageLoadPanel.Size = new System.Drawing.Size(300, 400);
            this.ImageLoadPanel.TabIndex = 3;
            this.ImageLoadPanel.TabStop = false;
            this.ImageLoadPanel.Click += new System.EventHandler(this.pictureBox1_Click);
            this.ImageLoadPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
            // 
            // Selected
            // 
            this.Selected.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Selected.Location = new System.Drawing.Point(0, 0);
            this.Selected.Name = "Selected";
            this.Selected.Size = new System.Drawing.Size(64, 64);
            this.Selected.TabIndex = 4;
            this.Selected.TabStop = false;
            // 
            // OpenTileSet
            // 
            this.OpenTileSet.BackColor = System.Drawing.SystemColors.Control;
            this.OpenTileSet.Image = global::Maptool.Properties.Resources.NewTileSet;
            this.OpenTileSet.Location = new System.Drawing.Point(70, 34);
            this.OpenTileSet.Name = "OpenTileSet";
            this.OpenTileSet.Size = new System.Drawing.Size(30, 30);
            this.OpenTileSet.TabIndex = 6;
            this.OpenTileSet.UseVisualStyleBackColor = false;
            this.OpenTileSet.Click += new System.EventHandler(this.OpenTileSet_Click);
            // 
            // DelTileSet
            // 
            this.DelTileSet.BackColor = System.Drawing.SystemColors.Control;
            this.DelTileSet.Image = global::Maptool.Properties.Resources.DelTileSet;
            this.DelTileSet.Location = new System.Drawing.Point(106, 34);
            this.DelTileSet.Name = "DelTileSet";
            this.DelTileSet.Size = new System.Drawing.Size(30, 30);
            this.DelTileSet.TabIndex = 7;
            this.DelTileSet.UseVisualStyleBackColor = false;
            this.DelTileSet.Click += new System.EventHandler(this.DelTileSet_Click);
            // 
            // SelectEmptyTile
            // 
            this.SelectEmptyTile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.SelectEmptyTile.Location = new System.Drawing.Point(228, 5);
            this.SelectEmptyTile.Name = "SelectEmptyTile";
            this.SelectEmptyTile.Size = new System.Drawing.Size(62, 57);
            this.SelectEmptyTile.TabIndex = 8;
            this.SelectEmptyTile.Text = "Empty Tile";
            this.SelectEmptyTile.UseVisualStyleBackColor = true;
            this.SelectEmptyTile.Click += new System.EventHandler(this.SelectEmptyTile_Click);
            // 
            // TileSelectForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(292, 469);
            this.Controls.Add(this.SelectEmptyTile);
            this.Controls.Add(this.DelTileSet);
            this.Controls.Add(this.OpenTileSet);
            this.Controls.Add(this.Selected);
            this.Controls.Add(this.ImageLoadPanel);
            this.Controls.Add(this.ImageIndex);
            this.Controls.Add(this.Next);
            this.Controls.Add(this.Prev);
            this.Location = new System.Drawing.Point(100, 100);
            this.Name = "TileSelectForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "TileSelectForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.TileSelectForm_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.ImageLoadPanel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Selected)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Prev;
        private System.Windows.Forms.Button Next;
        public System.Windows.Forms.PictureBox ImageLoadPanel;
        public System.Windows.Forms.Label ImageIndex;
        private System.Windows.Forms.PictureBox Selected;
        private System.Windows.Forms.Button OpenTileSet;
        private System.Windows.Forms.Button DelTileSet;
        private System.Windows.Forms.Button SelectEmptyTile;
    }
}