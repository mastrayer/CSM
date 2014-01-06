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
    public partial class new_map : Form
    {
        Main mainForm;

        public new_map(Main form)
        {
            mainForm = form;
            InitializeComponent();
            select_map_tile.SelectedIndex = 0;
        }

        private void input_map_size(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsDigit(e.KeyChar)) && e.KeyChar != Convert.ToChar(Keys.Back))
            {
                //숫자입력만 받도록 한다.
                e.Handled = true;
            }
                
        }

        private void button_ok_Click(object sender, EventArgs e)
        {
            mainForm.mainMap.Dispose();

            Main.mapInfo info = new Main.mapInfo(width.Text, height.Text, Title.Text);
            //mainForm.mainMap_init(Convert.ToInt32(this.width.Text), Convert.ToInt32(this.height.Text));
            mainForm.mainMap_init(info);

            this.Dispose();
//             int a = Convert.ToInt32(this.width.Text) * Convert.ToInt32(this.height.Text);
//             MessageBox.Show(a.ToString());
        }

        private void button_cancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void select_map_tile_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (select_map_tile.SelectedItem.ToString() == "더 찾아보기..")
            {
                System.IO.Stream openStream = null;
                OpenFileDialog open_tile = new OpenFileDialog();

                open_tile.InitialDirectory = "c:\\";
                open_tile.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                open_tile.FilterIndex = 2;
                open_tile.RestoreDirectory = true;

                if (open_tile.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        if ((openStream = open_tile.OpenFile()) != null)
                        {
                            using (openStream)
                            {
                                // Insert code to read the stream here.
                            }
                        }
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);
                    }
                }
                else
                    select_map_tile.SelectedIndex = 0;
            }
        }
    }
}
