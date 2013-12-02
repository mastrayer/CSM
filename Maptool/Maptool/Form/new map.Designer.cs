namespace Maptool
{
    partial class new_map
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
            this.button_ok = new System.Windows.Forms.Button();
            this.button_cancel = new System.Windows.Forms.Button();
            this.width = new System.Windows.Forms.TextBox();
            this.size = new System.Windows.Forms.Label();
            this.height = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.select_map_tile = new System.Windows.Forms.ComboBox();
            this.Title = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button_ok
            // 
            this.button_ok.Location = new System.Drawing.Point(59, 217);
            this.button_ok.Name = "button_ok";
            this.button_ok.Size = new System.Drawing.Size(62, 24);
            this.button_ok.TabIndex = 0;
            this.button_ok.Text = "OK";
            this.button_ok.UseVisualStyleBackColor = true;
            this.button_ok.Click += new System.EventHandler(this.button_ok_Click);
            // 
            // button_cancel
            // 
            this.button_cancel.Location = new System.Drawing.Point(151, 217);
            this.button_cancel.Name = "button_cancel";
            this.button_cancel.Size = new System.Drawing.Size(62, 24);
            this.button_cancel.TabIndex = 1;
            this.button_cancel.Text = "cancel";
            this.button_cancel.UseVisualStyleBackColor = true;
            this.button_cancel.Click += new System.EventHandler(this.button_cancel_Click);
            // 
            // width
            // 
            this.width.Location = new System.Drawing.Point(123, 51);
            this.width.MaxLength = 2;
            this.width.Name = "width";
            this.width.Size = new System.Drawing.Size(34, 21);
            this.width.TabIndex = 2;
            this.width.Text = "16";
            this.width.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.input_map_size);
            // 
            // size
            // 
            this.size.AutoSize = true;
            this.size.Location = new System.Drawing.Point(61, 55);
            this.size.Name = "size";
            this.size.Size = new System.Drawing.Size(58, 12);
            this.size.TabIndex = 3;
            this.size.Text = "map size";
            // 
            // height
            // 
            this.height.Location = new System.Drawing.Point(178, 51);
            this.height.MaxLength = 2;
            this.height.Name = "height";
            this.height.Size = new System.Drawing.Size(34, 21);
            this.height.TabIndex = 4;
            this.height.Text = "16";
            this.height.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.input_map_size);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(161, 57);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(13, 12);
            this.label1.TabIndex = 5;
            this.label1.Text = "X";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(63, 86);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 12);
            this.label2.TabIndex = 6;
            this.label2.Text = "Map tile";
            // 
            // select_map_tile
            // 
            this.select_map_tile.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.select_map_tile.FormattingEnabled = true;
            this.select_map_tile.Items.AddRange(new object[] {
            "Default",
            "더 찾아보기.."});
            this.select_map_tile.Location = new System.Drawing.Point(123, 86);
            this.select_map_tile.Name = "select_map_tile";
            this.select_map_tile.Size = new System.Drawing.Size(89, 20);
            this.select_map_tile.TabIndex = 7;
            this.select_map_tile.SelectedIndexChanged += new System.EventHandler(this.select_map_tile_SelectedIndexChanged);
            // 
            // Title
            // 
            this.Title.Location = new System.Drawing.Point(123, 24);
            this.Title.MaxLength = 15;
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(89, 21);
            this.Title.TabIndex = 8;
            this.Title.Text = "Untitled";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(63, 27);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 9;
            this.label3.Text = "map title";
            // 
            // new_map
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(292, 269);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Title);
            this.Controls.Add(this.select_map_tile);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.height);
            this.Controls.Add(this.size);
            this.Controls.Add(this.width);
            this.Controls.Add(this.button_cancel);
            this.Controls.Add(this.button_ok);
            this.Name = "new_map";
            this.Text = "New";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button_ok;
        private System.Windows.Forms.Button button_cancel;
        private System.Windows.Forms.TextBox width;
        private System.Windows.Forms.Label size;
        private System.Windows.Forms.TextBox height;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox select_map_tile;
        private System.Windows.Forms.TextBox Title;
        private System.Windows.Forms.Label label3;

    }
}