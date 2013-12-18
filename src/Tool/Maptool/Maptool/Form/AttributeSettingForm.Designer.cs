namespace Maptool
{
    partial class AttributeSettingForm
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
            this.label18 = new System.Windows.Forms.Label();
            this.attribute_move = new System.Windows.Forms.CheckBox();
            this.attribute_height = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(12, 31);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(39, 12);
            this.label18.TabIndex = 3;
            this.label18.Text = "height";
            // 
            // attribute_move
            // 
            this.attribute_move.AutoSize = true;
            this.attribute_move.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.attribute_move.Location = new System.Drawing.Point(12, 12);
            this.attribute_move.Name = "attribute_move";
            this.attribute_move.Size = new System.Drawing.Size(55, 16);
            this.attribute_move.TabIndex = 2;
            this.attribute_move.Text = "move";
            this.attribute_move.UseVisualStyleBackColor = true;
            this.attribute_move.CheckStateChanged += new System.EventHandler(this.attribute_move_CheckStateChanged);
            // 
            // attribute_height
            // 
            this.attribute_height.Location = new System.Drawing.Point(53, 28);
            this.attribute_height.MaxLength = 1;
            this.attribute_height.Name = "attribute_height";
            this.attribute_height.Size = new System.Drawing.Size(14, 21);
            this.attribute_height.TabIndex = 4;
            this.attribute_height.Text = "0";
            this.attribute_height.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.attribute_height_TextChanged);
            // 
            // AttributeSettingForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(184, 84);
            this.ControlBox = false;
            this.Controls.Add(this.attribute_height);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.attribute_move);
            this.Name = "AttributeSettingForm";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Text = "Attribute";
            this.TopMost = true;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.AttributeSettingForm_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.CheckBox attribute_move;
        private System.Windows.Forms.TextBox attribute_height;
    }
}