using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Maptool
{
    public partial class AttributeSettingForm : Form
    {
        private Main mainForm;

        public int height;
        public bool move;

        public AttributeSettingForm(Main form)
        {
            InitializeComponent();
            mainForm = form;
        }

        private void AttributeSettingForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
            ((AttributeSettingForm)sender).Hide();
        }

        private void attribute_move_CheckStateChanged(object sender, EventArgs e)
        {
            move = ((CheckBox)sender).Checked;
        }
        private void attribute_height_TextChanged(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsDigit(e.KeyChar)) && e.KeyChar != Convert.ToChar(Keys.Back))
            {
                //숫자입력만 받도록 한다.
                e.Handled = true;
            }
            else
                height = Convert.ToInt32(((TextBox)sender).Text);
        }
    }
}
