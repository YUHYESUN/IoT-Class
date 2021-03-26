using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBManagerEx
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        SqlConnection sqlconn = new SqlConnection();
        SqlCommand sqlcom = new SqlCommand();

        private void MenuNew_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();

            sbPanel1.Text = "DB File Name";
            sbPanelbtn1.Text = "Table list";
            sbPanelbtn1.DropDownItems.Clear();
            sbPanel2.Text = "Initialized";
            sqlconn.Close();

        }

        private void openMigrationToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() != DialogResult.OK) return;

            string fname = openFileDialog1.FileName;

            StreamReader sr = new StreamReader(fname);

            string buf= sr.ReadLine();

            string[] Arr = buf.Split(',');

            for(int i=0; i<Arr.Length; i++)
            {

                dataGridView1.Columns.Add("col",Arr[i]);

            }

            while (true)
            {

                buf = sr.ReadLine();

                if (buf == null) break;

                Arr = buf.Split(',');

                dataGridView1.Rows.Add(Arr);

            }

            sr.Close();


        }

        private void MenuSave_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() != DialogResult.OK) return;

            StreamWriter sw = new StreamWriter(saveFileDialog1.FileName,false,Encoding.Default);

            string buf = "";

            for(int i=0; i<dataGridView1.Columns.Count; i++)
            {

                buf += dataGridView1.Columns[i].HeaderText;

                if (i < dataGridView1.Columns.Count - 1)
                {
                    buf += ",";
                }

            }

            sw.Write(buf + "\r\n");

            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                buf = "";
                for (int j = 0; j < dataGridView1.Columns.Count; j++)
                {
                    buf += dataGridView1.Rows[i].Cells[j].Value;
                    if (j < dataGridView1.Columns.Count - 1) buf += ",";

                }

                sw.Write(buf + "\r\n");
            }
            sw.Close();






        }
    }
}
