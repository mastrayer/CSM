namespace Maptool
{
    partial class HelpForm
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
            System.Windows.Forms.TreeNode treeNode12 = new System.Windows.Forms.TreeNode("New");
            System.Windows.Forms.TreeNode treeNode13 = new System.Windows.Forms.TreeNode("Open");
            System.Windows.Forms.TreeNode treeNode14 = new System.Windows.Forms.TreeNode("Save");
            System.Windows.Forms.TreeNode treeNode15 = new System.Windows.Forms.TreeNode("기능 설명", new System.Windows.Forms.TreeNode[] {
            treeNode12,
            treeNode13,
            treeNode14});
            System.Windows.Forms.TreeNode treeNode16 = new System.Windows.Forms.TreeNode("시작하기", new System.Windows.Forms.TreeNode[] {
            treeNode15});
            System.Windows.Forms.TreeNode treeNode17 = new System.Windows.Forms.TreeNode("노드10");
            System.Windows.Forms.TreeNode treeNode18 = new System.Windows.Forms.TreeNode("노드11");
            System.Windows.Forms.TreeNode treeNode19 = new System.Windows.Forms.TreeNode("노드12");
            System.Windows.Forms.TreeNode treeNode20 = new System.Windows.Forms.TreeNode("노드13");
            System.Windows.Forms.TreeNode treeNode21 = new System.Windows.Forms.TreeNode("편의 기능", new System.Windows.Forms.TreeNode[] {
            treeNode17,
            treeNode18,
            treeNode19,
            treeNode20});
            System.Windows.Forms.TreeNode treeNode22 = new System.Windows.Forms.TreeNode("만든 사람");
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.textArea = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // treeView1
            // 
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Left;
            this.treeView1.Location = new System.Drawing.Point(0, 0);
            this.treeView1.Name = "treeView1";
            treeNode12.Name = "노드6";
            treeNode12.Text = "New";
            treeNode13.Name = "노드7";
            treeNode13.Text = "Open";
            treeNode14.Name = "노드8";
            treeNode14.Text = "Save";
            treeNode15.Name = "노드1";
            treeNode15.Text = "기능 설명";
            treeNode16.Name = "노드0";
            treeNode16.Text = "시작하기";
            treeNode17.Name = "노드10";
            treeNode17.Text = "노드10";
            treeNode18.Name = "노드11";
            treeNode18.Text = "노드11";
            treeNode19.Name = "노드12";
            treeNode19.Text = "노드12";
            treeNode20.Name = "노드13";
            treeNode20.Text = "노드13";
            treeNode21.Name = "노드5";
            treeNode21.Text = "편의 기능";
            treeNode22.Name = "노드9";
            treeNode22.Text = "만든 사람";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode16,
            treeNode21,
            treeNode22});
            this.treeView1.Size = new System.Drawing.Size(161, 527);
            this.treeView1.TabIndex = 0;
            this.treeView1.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.treeView1_NodeMouseClick);
            // 
            // textArea
            // 
            this.textArea.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textArea.Location = new System.Drawing.Point(161, 0);
            this.textArea.Name = "textArea";
            this.textArea.ReadOnly = true;
            this.textArea.Size = new System.Drawing.Size(508, 527);
            this.textArea.TabIndex = 1;
            this.textArea.Text = "";
            // 
            // HelpForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(669, 527);
            this.Controls.Add(this.textArea);
            this.Controls.Add(this.treeView1);
            this.Name = "HelpForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.HelpForm_FormClosing);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.RichTextBox textArea;
    }
}