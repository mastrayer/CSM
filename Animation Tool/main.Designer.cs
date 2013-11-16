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
            this.spritePanel = new System.Windows.Forms.Panel();
            this.toolStrip2 = new System.Windows.Forms.ToolStrip();
            this.toolStripLabel1 = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.ButtonSpriteAdd = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.ButtonSpriteDelete = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.workSpace = new System.Windows.Forms.PictureBox();
            this.attribute = new System.Windows.Forms.Panel();
            this.label3 = new System.Windows.Forms.Label();
            this.AttributePlayTime = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.AttributeSpriteLotate = new System.Windows.Forms.TextBox();
            this.AttributeSpriteRotateLabel = new System.Windows.Forms.Label();
            this.AttributeSpriteHeight = new System.Windows.Forms.TextBox();
            this.AttributeSpriteHeightLabel = new System.Windows.Forms.Label();
            this.AttributeSpriteWidth = new System.Windows.Forms.TextBox();
            this.SpriteY = new System.Windows.Forms.TextBox();
            this.SpritePositionYLabel = new System.Windows.Forms.Label();
            this.SpriteX = new System.Windows.Forms.TextBox();
            this.SpritePositionXLabel = new System.Windows.Forms.Label();
            this.AttributeSpriteWidthLabel = new System.Windows.Forms.Label();
            this.timeline = new System.Windows.Forms.Panel();
            this.menu.SuspendLayout();
            this.menuIcon.SuspendLayout();
            this.mainPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.toolStrip2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.workSpace)).BeginInit();
            this.attribute.SuspendLayout();
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
            this.splitContainer1.Panel1.Controls.Add(this.spritePanel);
            this.splitContainer1.Panel1.Controls.Add(this.toolStrip2);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.workSpace);
            this.splitContainer1.Size = new System.Drawing.Size(678, 437);
            this.splitContainer1.SplitterDistance = 144;
            this.splitContainer1.TabIndex = 2;
            this.splitContainer1.SplitterMoved += new System.Windows.Forms.SplitterEventHandler(this.splitContainer1_SplitterMoved);
            // 
            // spritePanel
            // 
            this.spritePanel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.spritePanel.Location = new System.Drawing.Point(3, 26);
            this.spritePanel.Name = "spritePanel";
            this.spritePanel.Size = new System.Drawing.Size(136, 406);
            this.spritePanel.TabIndex = 2;
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
            this.toolStrip2.Size = new System.Drawing.Size(142, 25);
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
            this.ButtonSpriteDelete.Click += new System.EventHandler(this.ButtonSpriteDelete_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
            // 
            // workSpace
            // 
            this.workSpace.BackColor = System.Drawing.SystemColors.Control;
            this.workSpace.Dock = System.Windows.Forms.DockStyle.Fill;
            this.workSpace.Location = new System.Drawing.Point(0, 0);
            this.workSpace.Name = "workSpace";
            this.workSpace.Padding = new System.Windows.Forms.Padding(5);
            this.workSpace.Size = new System.Drawing.Size(528, 435);
            this.workSpace.TabIndex = 0;
            this.workSpace.TabStop = false;
            // 
            // attribute
            // 
            this.attribute.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.attribute.Controls.Add(this.label3);
            this.attribute.Controls.Add(this.AttributePlayTime);
            this.attribute.Controls.Add(this.label2);
            this.attribute.Controls.Add(this.label1);
            this.attribute.Controls.Add(this.AttributeSpriteLotate);
            this.attribute.Controls.Add(this.AttributeSpriteRotateLabel);
            this.attribute.Controls.Add(this.AttributeSpriteHeight);
            this.attribute.Controls.Add(this.AttributeSpriteHeightLabel);
            this.attribute.Controls.Add(this.AttributeSpriteWidth);
            this.attribute.Controls.Add(this.SpriteY);
            this.attribute.Controls.Add(this.SpritePositionYLabel);
            this.attribute.Controls.Add(this.SpriteX);
            this.attribute.Controls.Add(this.SpritePositionXLabel);
            this.attribute.Controls.Add(this.AttributeSpriteWidthLabel);
            this.attribute.Dock = System.Windows.Forms.DockStyle.Right;
            this.attribute.Location = new System.Drawing.Point(678, 0);
            this.attribute.Name = "attribute";
            this.attribute.Size = new System.Drawing.Size(114, 437);
            this.attribute.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(73, 215);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(23, 12);
            this.label3.TabIndex = 18;
            this.label3.Text = "ms";
            // 
            // AttributePlayTime
            // 
            this.AttributePlayTime.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.AttributePlayTime.Location = new System.Drawing.Point(32, 209);
            this.AttributePlayTime.MaxLength = 4;
            this.AttributePlayTime.Name = "AttributePlayTime";
            this.AttributePlayTime.Size = new System.Drawing.Size(40, 21);
            this.AttributePlayTime.TabIndex = 17;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(5, 215);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 16;
            this.label2.Text = "time";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(73, 188);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(15, 12);
            this.label1.TabIndex = 15;
            this.label1.Text = "%";
            // 
            // AttributeSpriteLotate
            // 
            this.AttributeSpriteLotate.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.AttributeSpriteLotate.Location = new System.Drawing.Point(43, 182);
            this.AttributeSpriteLotate.MaxLength = 3;
            this.AttributeSpriteLotate.Name = "AttributeSpriteLotate";
            this.AttributeSpriteLotate.Size = new System.Drawing.Size(29, 21);
            this.AttributeSpriteLotate.TabIndex = 14;
            // 
            // AttributeSpriteRotateLabel
            // 
            this.AttributeSpriteRotateLabel.AutoSize = true;
            this.AttributeSpriteRotateLabel.Location = new System.Drawing.Point(5, 188);
            this.AttributeSpriteRotateLabel.Name = "AttributeSpriteRotateLabel";
            this.AttributeSpriteRotateLabel.Size = new System.Drawing.Size(40, 12);
            this.AttributeSpriteRotateLabel.TabIndex = 13;
            this.AttributeSpriteRotateLabel.Text = "Rotate";
            // 
            // AttributeSpriteHeight
            // 
            this.AttributeSpriteHeight.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.AttributeSpriteHeight.Location = new System.Drawing.Point(43, 155);
            this.AttributeSpriteHeight.MaxLength = 3;
            this.AttributeSpriteHeight.Name = "AttributeSpriteHeight";
            this.AttributeSpriteHeight.Size = new System.Drawing.Size(29, 21);
            this.AttributeSpriteHeight.TabIndex = 12;
            // 
            // AttributeSpriteHeightLabel
            // 
            this.AttributeSpriteHeightLabel.AutoSize = true;
            this.AttributeSpriteHeightLabel.Location = new System.Drawing.Point(5, 161);
            this.AttributeSpriteHeightLabel.Name = "AttributeSpriteHeightLabel";
            this.AttributeSpriteHeightLabel.Size = new System.Drawing.Size(40, 12);
            this.AttributeSpriteHeightLabel.TabIndex = 11;
            this.AttributeSpriteHeightLabel.Text = "Height";
            // 
            // AttributeSpriteWidth
            // 
            this.AttributeSpriteWidth.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.AttributeSpriteWidth.Location = new System.Drawing.Point(43, 128);
            this.AttributeSpriteWidth.MaxLength = 3;
            this.AttributeSpriteWidth.Name = "AttributeSpriteWidth";
            this.AttributeSpriteWidth.Size = new System.Drawing.Size(29, 21);
            this.AttributeSpriteWidth.TabIndex = 10;
            // 
            // SpriteY
            // 
            this.SpriteY.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.SpriteY.Location = new System.Drawing.Point(72, 101);
            this.SpriteY.MaxLength = 3;
            this.SpriteY.Name = "SpriteY";
            this.SpriteY.Size = new System.Drawing.Size(29, 21);
            this.SpriteY.TabIndex = 9;
            // 
            // SpritePositionYLabel
            // 
            this.SpritePositionYLabel.AutoSize = true;
            this.SpritePositionYLabel.Location = new System.Drawing.Point(59, 104);
            this.SpritePositionYLabel.Name = "SpritePositionYLabel";
            this.SpritePositionYLabel.Size = new System.Drawing.Size(13, 12);
            this.SpritePositionYLabel.TabIndex = 8;
            this.SpritePositionYLabel.Text = "Y";
            // 
            // SpriteX
            // 
            this.SpriteX.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.SpriteX.Location = new System.Drawing.Point(16, 101);
            this.SpriteX.MaxLength = 3;
            this.SpriteX.Name = "SpriteX";
            this.SpriteX.Size = new System.Drawing.Size(29, 21);
            this.SpriteX.TabIndex = 7;
            // 
            // SpritePositionXLabel
            // 
            this.SpritePositionXLabel.AutoSize = true;
            this.SpritePositionXLabel.Location = new System.Drawing.Point(3, 104);
            this.SpritePositionXLabel.Name = "SpritePositionXLabel";
            this.SpritePositionXLabel.Size = new System.Drawing.Size(13, 12);
            this.SpritePositionXLabel.TabIndex = 6;
            this.SpritePositionXLabel.Text = "X";
            // 
            // AttributeSpriteWidthLabel
            // 
            this.AttributeSpriteWidthLabel.AutoSize = true;
            this.AttributeSpriteWidthLabel.Location = new System.Drawing.Point(5, 134);
            this.AttributeSpriteWidthLabel.Name = "AttributeSpriteWidthLabel";
            this.AttributeSpriteWidthLabel.Size = new System.Drawing.Size(35, 12);
            this.AttributeSpriteWidthLabel.TabIndex = 1;
            this.AttributeSpriteWidthLabel.Text = "Width";
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
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.toolStrip2.ResumeLayout(false);
            this.toolStrip2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.workSpace)).EndInit();
            this.attribute.ResumeLayout(false);
            this.attribute.PerformLayout();
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
        private System.Windows.Forms.PictureBox workSpace;
        private System.Windows.Forms.ToolStrip toolStrip2;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        private System.Windows.Forms.ToolStripButton ButtonSpriteAdd;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton ButtonSpriteDelete;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.Panel spritePanel;
        private System.Windows.Forms.TextBox AttributeSpriteHeight;
        private System.Windows.Forms.Label AttributeSpriteHeightLabel;
        private System.Windows.Forms.TextBox AttributeSpriteWidth;
        private System.Windows.Forms.TextBox SpriteY;
        private System.Windows.Forms.Label SpritePositionYLabel;
        private System.Windows.Forms.TextBox SpriteX;
        private System.Windows.Forms.Label SpritePositionXLabel;
        private System.Windows.Forms.Label AttributeSpriteWidthLabel;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox AttributePlayTime;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox AttributeSpriteLotate;
        private System.Windows.Forms.Label AttributeSpriteRotateLabel;
    }
}

