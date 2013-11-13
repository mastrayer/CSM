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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.image_panel = new System.Windows.Forms.Panel();
            this.aaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.timeline_panel = new System.Windows.Forms.Panel();
            this.attribute_panel = new System.Windows.Forms.Panel();
            this.work_panel = new System.Windows.Forms.Panel();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aaToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(932, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // image_panel
            // 
            this.image_panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.image_panel.Location = new System.Drawing.Point(0, 27);
            this.image_panel.Name = "image_panel";
            this.image_panel.Size = new System.Drawing.Size(189, 593);
            this.image_panel.TabIndex = 1;
            // 
            // aaToolStripMenuItem
            // 
            this.aaToolStripMenuItem.Name = "aaToolStripMenuItem";
            this.aaToolStripMenuItem.Size = new System.Drawing.Size(31, 20);
            this.aaToolStripMenuItem.Text = "aa";
            // 
            // timeline_panel
            // 
            this.timeline_panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.timeline_panel.Location = new System.Drawing.Point(195, 509);
            this.timeline_panel.Name = "timeline_panel";
            this.timeline_panel.Size = new System.Drawing.Size(737, 111);
            this.timeline_panel.TabIndex = 2;
            // 
            // attribute_panel
            // 
            this.attribute_panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.attribute_panel.Location = new System.Drawing.Point(830, 27);
            this.attribute_panel.Name = "attribute_panel";
            this.attribute_panel.Size = new System.Drawing.Size(102, 476);
            this.attribute_panel.TabIndex = 3;
            // 
            // work_panel
            // 
            this.work_panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.work_panel.Location = new System.Drawing.Point(195, 27);
            this.work_panel.Name = "work_panel";
            this.work_panel.Size = new System.Drawing.Size(629, 476);
            this.work_panel.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(932, 621);
            this.Controls.Add(this.work_panel);
            this.Controls.Add(this.attribute_panel);
            this.Controls.Add(this.timeline_panel);
            this.Controls.Add(this.image_panel);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "CSM Animation Tool";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.Panel image_panel;
        private System.Windows.Forms.ToolStripMenuItem aaToolStripMenuItem;
        private System.Windows.Forms.Panel timeline_panel;
        private System.Windows.Forms.Panel attribute_panel;
        private System.Windows.Forms.Panel work_panel;
    }
}

