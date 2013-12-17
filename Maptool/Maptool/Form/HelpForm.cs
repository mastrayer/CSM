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
    public partial class HelpForm : Form
    {
        public HelpForm()
        {
            InitializeComponent();
        }

        private void HelpForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
            ((HelpForm)sender).Hide();
        }

        private void treeView1_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            TreeView tree = (TreeView)sender;

            if (e.Node.Text == "시작하기")
            {
                MessageBox.Show("시작하기");
            }

            else if (e.Node.Text == "기능 설명") MessageBox.Show("기능 설명");

            else if (e.Node.Text == "New") MessageBox.Show("New");
            else if (e.Node.Text == "Open") MessageBox.Show("Open");
            else if (e.Node.Text == "Save") MessageBox.Show("Save");

            else if (e.Node.Text == "편의 기능") MessageBox.Show("편의 기능");

            else if (e.Node.Text == "만든 사람") MessageBox.Show("만든 사람");

        }
    }
}
