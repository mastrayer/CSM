namespace Animation_Tool
{
    partial class play
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
            this.playScene = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.playScene)).BeginInit();
            this.SuspendLayout();
            // 
            // playScene
            // 
            this.playScene.Dock = System.Windows.Forms.DockStyle.Fill;
            this.playScene.Location = new System.Drawing.Point(0, 0);
            this.playScene.Name = "playScene";
            this.playScene.Size = new System.Drawing.Size(292, 269);
            this.playScene.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.playScene.TabIndex = 0;
            this.playScene.TabStop = false;
            // 
            // play
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(292, 269);
            this.ControlBox = false;
            this.Controls.Add(this.playScene);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "play";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Text = "play";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.play_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.playScene)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox playScene;

    }
}