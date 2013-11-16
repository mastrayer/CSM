namespace Animation_Tool
{
    partial class main
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(main));
            this.menu = new System.Windows.Forms.MenuStrip();
            this.sasdsa = new System.Windows.Forms.ToolStripMenuItem();
            this.menuIcon = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.mainPanel = new System.Windows.Forms.Panel();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.toolStrip2 = new System.Windows.Forms.ToolStrip();
            this.toolStripLabel1 = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.ButtonSpriteAdd = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.ButtonSpriteDelete = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.LoadedSprite = new System.Windows.Forms.PictureBox();
            this.attribute = new System.Windows.Forms.Panel();
            this.timeline = new System.Windows.Forms.Panel();
            this.menu.SuspendLayout();
            this.menuIcon.SuspendLayout();
            this.mainPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.toolStrip2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LoadedSprite)).BeginInit();
            this.SuspendLayout();
            // 
            // menu
            // 
            this.menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sasdsa});
            this.menu.Location = new System.Drawing.Point(0, 0);
            this.menu.Name = "menu";
            this.menu.Size = new System.Drawing.Size(792, 24);
            this.menu.TabIndex = 0;
            this.menu.Text = "menuStrip1";
            // 
            // sasdsa
            // 
            this.sasdsa.Name = "sasdsa";
            this.sasdsa.Size = new System.Drawing.Size(31, 20);
            this.sasdsa.Text = "aa";
            // 
            // menuIcon
            // 
            this.menuIcon.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1});
            this.menuIcon.Location = new System.Drawing.Point(0, 24);
            this.menuIcon.Name = "menuIcon";
            this.menuIcon.Size = new System.Drawing.Size(792, 25);
            this.menuIcon.TabIndex = 1;
            this.menuIcon.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton1.Text = "toolStripButton1";
            // 
            // mainPanel
            // 
            this.mainPanel.Controls.Add(this.splitContainer1);
            this.mainPanel.Controls.Add(this.attribute);
            this.mainPanel.Controls.Add(this.timeline);
            this.mainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainPanel.Location = new System.Drawing.Point(0, 49);
            this.mainPanel.Name = "mainPanel";
            this.mainPanel.Size = new System.Drawing.Size(792, 520);
            this.mainPanel.TabIndex = 2;
            // 
            // splitContainer1
            // 
            this.splitContainer1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.AutoScroll = true;
            this.splitContainer1.Panel1.Controls.Add(this.toolStrip2);
            this.splitContainer1.Panel1.Controls.Add(this.LoadedSprite);
            this.splitContainer1.Size = new System.Drawing.Size(706, 437);
            this.splitContainer1.SplitterDistance = 179;
            this.splitContainer1.TabIndex = 2;
            // 
            // toolStrip2
            // 
            this.toolStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripLabel1,
            this.toolStripSeparator1,
            this.ButtonSpriteAdd,
            this.toolStripSeparator2,
            this.ButtonSpriteDelete,
            this.toolStripSeparator3});
            this.toolStrip2.Location = new System.Drawing.Point(0, 0);
            this.toolStrip2.Name = "toolStrip2";
            this.toolStrip2.Size = new System.Drawing.Size(177, 25);
            this.toolStrip2.TabIndex = 1;
            // 
            // toolStripLabel1
            // 
            this.toolStripLabel1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripLabel1.Name = "toolStripLabel1";
            this.toolStripLabel1.Size = new System.Drawing.Size(43, 22);
            this.toolStripLabel1.Text = "Sprites";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // ButtonSpriteAdd
            // 
            this.ButtonSpriteAdd.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.ButtonSpriteAdd.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.ButtonSpriteAdd.Name = "ButtonSpriteAdd";
            this.ButtonSpriteAdd.Size = new System.Drawing.Size(23, 22);
            this.ButtonSpriteAdd.Text = "+";
            this.ButtonSpriteAdd.Click += new System.EventHandler(this.ButtonSpriteAdd_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // ButtonSpriteDelete
            // 
            this.ButtonSpriteDelete.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.ButtonSpriteDelete.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.ButtonSpriteDelete.Name = "ButtonSpriteDelete";
            this.ButtonSpriteDelete.Size = new System.Drawing.Size(23, 22);
            this.ButtonSpriteDelete.Text = "-";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
            // 
            // LoadedSprite
            // 
            this.LoadedSprite.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.LoadedSprite.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.LoadedSprite.Location = new System.Drawing.Point(-1, 28);
            this.LoadedSprite.Name = "LoadedSprite";
            this.LoadedSprite.Size = new System.Drawing.Size(175, 404);
            this.LoadedSprite.TabIndex = 0;
            this.LoadedSprite.TabStop = false;
            // 
            // attribute
            // 
            this.attribute.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.attribute.Dock = System.Windows.Forms.DockStyle.Right;
            this.attribute.Location = new System.Drawing.Point(706, 0);
            this.attribute.Name = "attribute";
            this.attribute.Size = new System.Drawing.Size(86, 437);
            this.attribute.TabIndex = 1;
            // 
            // timeline
            // 
            this.timeline.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.timeline.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.timeline.Location = new System.Drawing.Point(0, 437);
            this.timeline.Name = "timeline";
            this.timeline.Size = new System.Drawing.Size(792, 83);
            this.timeline.TabIndex = 0;
            // 
            // main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(792, 569);
            this.Controls.Add(this.mainPanel);
            this.Controls.Add(this.menuIcon);
            this.Controls.Add(this.menu);
            this.MainMenuStrip = this.menu;
            this.Name = "main";
            this.Text = "CSM Animation Tool";
            this.menu.ResumeLayout(false);
            this.menu.PerformLayout();
            this.menuIcon.ResumeLayout(false);
            this.menuIcon.PerformLayout();
            this.mainPanel.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.toolStrip2.ResumeLayout(false);
            this.toolStrip2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LoadedSprite)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menu;
        private System.Windows.Forms.ToolStripMenuItem sasdsa;
        private System.Windows.Forms.ToolStrip menuIcon;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.Panel mainPanel;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Panel attribute;
        private System.Windows.Forms.Panel timeline;
        private System.Windows.Forms.PictureBox LoadedSprite;
        private System.Windows.Forms.ToolStrip toolStrip2;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        private System.Windows.Forms.ToolStripButton ButtonSpriteAdd;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton ButtonSpriteDelete;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
    }
}

