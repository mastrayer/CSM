namespace Maptool
{
    partial class Main
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Main));
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Starting Point");
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("Crown");
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("barrack");
            System.Windows.Forms.TreeNode treeNode8 = new System.Windows.Forms.TreeNode("Object", new System.Windows.Forms.TreeNode[] {
            treeNode5,
            treeNode6,
            treeNode7});
            this.메뉴 = new System.Windows.Forms.MenuStrip();
            this.menu_file = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_new = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_open = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.menu_item_close = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_close_all = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.menu_item_save = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_save_as = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.menu_item_recent_file = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.menu_item_exit = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_edit = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_undo = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_redo = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.menu_item_cut = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_copy = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_paste = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_delete = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.menu_item_select_all = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_view = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_tool = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_help = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_view_help = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_report_a_bug = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_info = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.contents = new System.Windows.Forms.TreeView();
            this.minimap = new System.Windows.Forms.PictureBox();
            this.layers = new System.Windows.Forms.ComboBox();
            this.button_load = new System.Windows.Forms.Button();
            this.button_save = new System.Windows.Forms.Button();
            this.button_new = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.main_map_panel = new System.Windows.Forms.Panel();
            this.magnification = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.status_panel = new System.Windows.Forms.Panel();
            this.Attribute_panel = new System.Windows.Forms.Panel();
            this.CurrentTileInfo_Position = new System.Windows.Forms.Label();
            this.attribute_index = new System.Windows.Forms.Label();
            this.attribute_height = new System.Windows.Forms.TextBox();
            this.label18 = new System.Windows.Forms.Label();
            this.attribute_move = new System.Windows.Forms.CheckBox();
            this.label19 = new System.Windows.Forms.Label();
            this.attribute_ObjectType = new System.Windows.Forms.Label();
            this.메뉴.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.minimap)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.status_panel.SuspendLayout();
            this.Attribute_panel.SuspendLayout();
            this.SuspendLayout();
            // 
            // 메뉴
            // 
            this.메뉴.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_file,
            this.menu_edit,
            this.menu_view,
            this.menu_tool,
            this.menu_help,
            this.toolStripMenuItem1});
            this.메뉴.Location = new System.Drawing.Point(0, 0);
            this.메뉴.Name = "메뉴";
            this.메뉴.Size = new System.Drawing.Size(1016, 24);
            this.메뉴.TabIndex = 0;
            this.메뉴.Text = "menuStrip1";
            // 
            // menu_file
            // 
            this.menu_file.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_item_new,
            this.menu_item_open,
            this.toolStripSeparator3,
            this.menu_item_close,
            this.menu_item_close_all,
            this.toolStripSeparator6,
            this.menu_item_save,
            this.menu_item_save_as,
            this.toolStripSeparator2,
            this.menu_item_recent_file,
            this.toolStripSeparator1,
            this.menu_item_exit});
            this.menu_file.Name = "menu_file";
            this.menu_file.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F)));
            this.menu_file.Size = new System.Drawing.Size(57, 20);
            this.menu_file.Text = "파일(&F)";
            // 
            // menu_item_new
            // 
            this.menu_item_new.Image = ((System.Drawing.Image)(resources.GetObject("menu_item_new.Image")));
            this.menu_item_new.Name = "menu_item_new";
            this.menu_item_new.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.menu_item_new.Size = new System.Drawing.Size(220, 22);
            this.menu_item_new.Text = "새로 만들기";
            this.menu_item_new.Click += new System.EventHandler(this.menu_item_new_Click);
            // 
            // menu_item_open
            // 
            this.menu_item_open.Image = global::Maptool.Properties.Resources.load;
            this.menu_item_open.Name = "menu_item_open";
            this.menu_item_open.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.menu_item_open.Size = new System.Drawing.Size(220, 22);
            this.menu_item_open.Text = "열기";
            this.menu_item_open.Click += new System.EventHandler(this.menu_item_open_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(217, 6);
            // 
            // menu_item_close
            // 
            this.menu_item_close.Name = "menu_item_close";
            this.menu_item_close.Size = new System.Drawing.Size(220, 22);
            this.menu_item_close.Text = "닫기";
            // 
            // menu_item_close_all
            // 
            this.menu_item_close_all.Name = "menu_item_close_all";
            this.menu_item_close_all.Size = new System.Drawing.Size(220, 22);
            this.menu_item_close_all.Text = "모두 닫기";
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(217, 6);
            // 
            // menu_item_save
            // 
            this.menu_item_save.Image = ((System.Drawing.Image)(resources.GetObject("menu_item_save.Image")));
            this.menu_item_save.Name = "menu_item_save";
            this.menu_item_save.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.menu_item_save.Size = new System.Drawing.Size(220, 22);
            this.menu_item_save.Text = "저장";
            this.menu_item_save.Click += new System.EventHandler(this.menu_item_save_Click);
            // 
            // menu_item_save_as
            // 
            this.menu_item_save_as.Name = "menu_item_save_as";
            this.menu_item_save_as.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.menu_item_save_as.Size = new System.Drawing.Size(220, 22);
            this.menu_item_save_as.Text = "다른 이름으로 저장";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(217, 6);
            // 
            // menu_item_recent_file
            // 
            this.menu_item_recent_file.Name = "menu_item_recent_file";
            this.menu_item_recent_file.Size = new System.Drawing.Size(220, 22);
            this.menu_item_recent_file.Text = "최근에 사용한 파일";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(217, 6);
            // 
            // menu_item_exit
            // 
            this.menu_item_exit.Name = "menu_item_exit";
            this.menu_item_exit.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
            this.menu_item_exit.Size = new System.Drawing.Size(220, 22);
            this.menu_item_exit.Text = "끝내기";
            this.menu_item_exit.Click += new System.EventHandler(this.menu_item_exit_Click);
            // 
            // menu_edit
            // 
            this.menu_edit.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_item_undo,
            this.menu_item_redo,
            this.toolStripSeparator4,
            this.menu_item_cut,
            this.menu_item_copy,
            this.menu_item_paste,
            this.menu_item_delete,
            this.toolStripSeparator5,
            this.menu_item_select_all});
            this.menu_edit.Name = "menu_edit";
            this.menu_edit.ShowShortcutKeys = false;
            this.menu_edit.Size = new System.Drawing.Size(57, 20);
            this.menu_edit.Text = "편집(&E)";
            // 
            // menu_item_undo
            // 
            this.menu_item_undo.Name = "menu_item_undo";
            this.menu_item_undo.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
            this.menu_item_undo.Size = new System.Drawing.Size(168, 22);
            this.menu_item_undo.Text = "실행 취소";
            // 
            // menu_item_redo
            // 
            this.menu_item_redo.Name = "menu_item_redo";
            this.menu_item_redo.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Y)));
            this.menu_item_redo.Size = new System.Drawing.Size(168, 22);
            this.menu_item_redo.Text = "다시 실행";
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(165, 6);
            // 
            // menu_item_cut
            // 
            this.menu_item_cut.Name = "menu_item_cut";
            this.menu_item_cut.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
            this.menu_item_cut.Size = new System.Drawing.Size(168, 22);
            this.menu_item_cut.Text = "잘라내기";
            // 
            // menu_item_copy
            // 
            this.menu_item_copy.Name = "menu_item_copy";
            this.menu_item_copy.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
            this.menu_item_copy.Size = new System.Drawing.Size(168, 22);
            this.menu_item_copy.Text = "복사";
            // 
            // menu_item_paste
            // 
            this.menu_item_paste.Name = "menu_item_paste";
            this.menu_item_paste.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
            this.menu_item_paste.Size = new System.Drawing.Size(168, 22);
            this.menu_item_paste.Text = "붙여넣기";
            // 
            // menu_item_delete
            // 
            this.menu_item_delete.Name = "menu_item_delete";
            this.menu_item_delete.ShortcutKeys = System.Windows.Forms.Keys.Delete;
            this.menu_item_delete.Size = new System.Drawing.Size(168, 22);
            this.menu_item_delete.Text = "삭제";
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(165, 6);
            // 
            // menu_item_select_all
            // 
            this.menu_item_select_all.Name = "menu_item_select_all";
            this.menu_item_select_all.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.menu_item_select_all.Size = new System.Drawing.Size(168, 22);
            this.menu_item_select_all.Text = "모두 선택";
            // 
            // menu_view
            // 
            this.menu_view.Name = "menu_view";
            this.menu_view.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.V)));
            this.menu_view.Size = new System.Drawing.Size(59, 20);
            this.menu_view.Text = "보기(&V)";
            // 
            // menu_tool
            // 
            this.menu_tool.Name = "menu_tool";
            this.menu_tool.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.T)));
            this.menu_tool.Size = new System.Drawing.Size(57, 20);
            this.menu_tool.Text = "도구(&T)";
            // 
            // menu_help
            // 
            this.menu_help.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_item_view_help,
            this.menu_item_report_a_bug,
            this.menu_item_info});
            this.menu_help.Name = "menu_help";
            this.menu_help.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.H)));
            this.menu_help.Size = new System.Drawing.Size(72, 20);
            this.menu_help.Text = "도움말(&H)";
            // 
            // menu_item_view_help
            // 
            this.menu_item_view_help.Name = "menu_item_view_help";
            this.menu_item_view_help.Size = new System.Drawing.Size(138, 22);
            this.menu_item_view_help.Text = "도움말 보기";
            this.menu_item_view_help.Click += new System.EventHandler(this.ShowHelpPage);
            // 
            // menu_item_report_a_bug
            // 
            this.menu_item_report_a_bug.Name = "menu_item_report_a_bug";
            this.menu_item_report_a_bug.Size = new System.Drawing.Size(138, 22);
            this.menu_item_report_a_bug.Text = "버그 보고";
            // 
            // menu_item_info
            // 
            this.menu_item_info.Name = "menu_item_info";
            this.menu_item_info.Size = new System.Drawing.Size(138, 22);
            this.menu_item_info.Text = "정보";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(12, 20);
            // 
            // contents
            // 
            this.contents.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.contents.Location = new System.Drawing.Point(0, 396);
            this.contents.Name = "contents";
            treeNode5.Name = "노드1";
            treeNode5.Text = "Starting Point";
            treeNode6.Name = "노드3";
            treeNode6.Text = "Crown";
            treeNode7.Name = "노드4";
            treeNode7.Text = "barrack";
            treeNode8.Name = "TreeNodeObject";
            treeNode8.Text = "Object";
            this.contents.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode8});
            this.contents.Size = new System.Drawing.Size(192, 323);
            this.contents.TabIndex = 3;
            this.contents.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.SelectObject);
            // 
            // minimap
            // 
            this.minimap.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.minimap.Location = new System.Drawing.Point(0, 80);
            this.minimap.Name = "minimap";
            this.minimap.Size = new System.Drawing.Size(192, 192);
            this.minimap.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.minimap.TabIndex = 2;
            this.minimap.TabStop = false;
            this.minimap.MouseDown += new System.Windows.Forms.MouseEventHandler(this.minimap_MouseDown);
            this.minimap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.minimap_MouseMove);
            this.minimap.MouseUp += new System.Windows.Forms.MouseEventHandler(this.minimap_MouseUp);
            // 
            // layers
            // 
            this.layers.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.layers.FormattingEnabled = true;
            this.layers.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.layers.Items.AddRange(new object[] {
            "Tile Layer",
            "Attribute Layer",
            "Object Layer"});
            this.layers.Location = new System.Drawing.Point(218, 47);
            this.layers.Name = "layers";
            this.layers.Size = new System.Drawing.Size(129, 20);
            this.layers.TabIndex = 9;
            this.layers.SelectedValueChanged += new System.EventHandler(this.layers_TextChanged);
            // 
            // button_load
            // 
            this.button_load.BackColor = System.Drawing.SystemColors.Control;
            this.button_load.Image = global::Maptool.Properties.Resources.load;
            this.button_load.Location = new System.Drawing.Point(36, 20);
            this.button_load.Name = "button_load";
            this.button_load.Size = new System.Drawing.Size(30, 30);
            this.button_load.TabIndex = 5;
            this.button_load.TabStop = false;
            this.button_load.UseVisualStyleBackColor = false;
            this.button_load.Click += new System.EventHandler(this.menu_item_open_Click);
            // 
            // button_save
            // 
            this.button_save.BackColor = System.Drawing.SystemColors.Control;
            this.button_save.Image = ((System.Drawing.Image)(resources.GetObject("button_save.Image")));
            this.button_save.Location = new System.Drawing.Point(72, 20);
            this.button_save.Name = "button_save";
            this.button_save.Size = new System.Drawing.Size(30, 30);
            this.button_save.TabIndex = 4;
            this.button_save.TabStop = false;
            this.button_save.UseVisualStyleBackColor = false;
            this.button_save.Click += new System.EventHandler(this.menu_item_save_Click);
            // 
            // button_new
            // 
            this.button_new.BackColor = System.Drawing.SystemColors.Control;
            this.button_new.Image = ((System.Drawing.Image)(resources.GetObject("button_new.Image")));
            this.button_new.ImageAlign = System.Drawing.ContentAlignment.TopRight;
            this.button_new.Location = new System.Drawing.Point(0, 20);
            this.button_new.Name = "button_new";
            this.button_new.Size = new System.Drawing.Size(30, 30);
            this.button_new.TabIndex = 6;
            this.button_new.TabStop = false;
            this.button_new.UseVisualStyleBackColor = false;
            this.button_new.Click += new System.EventHandler(this.menu_item_new_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button_new);
            this.groupBox1.Controls.Add(this.button_save);
            this.groupBox1.Controls.Add(this.button_load);
            this.groupBox1.Location = new System.Drawing.Point(12, 27);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 54);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "button";
            // 
            // main_map_panel
            // 
            this.main_map_panel.BackColor = System.Drawing.SystemColors.Control;
            this.main_map_panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.main_map_panel.CausesValidation = false;
            this.main_map_panel.Location = new System.Drawing.Point(192, 80);
            this.main_map_panel.Name = "main_map_panel";
            this.main_map_panel.Size = new System.Drawing.Size(824, 641);
            this.main_map_panel.TabIndex = 0;
            this.main_map_panel.TabStop = true;
            // 
            // magnification
            // 
            this.magnification.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.magnification.FormattingEnabled = true;
            this.magnification.Items.AddRange(new object[] {
            "10%",
            "20%",
            "30%",
            "50%",
            "70%",
            "90%",
            "100%",
            "120%",
            "150%",
            "200%",
            "400%"});
            this.magnification.Location = new System.Drawing.Point(353, 47);
            this.magnification.Name = "magnification";
            this.magnification.Size = new System.Drawing.Size(102, 20);
            this.magnification.TabIndex = 17;
            this.magnification.TextChanged += new System.EventHandler(this.magnification_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(-1, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "label1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(43, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 12);
            this.label2.TabIndex = 18;
            this.label2.Text = "label2";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(87, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(38, 12);
            this.label3.TabIndex = 19;
            this.label3.Text = "label3";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(131, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(38, 12);
            this.label4.TabIndex = 20;
            this.label4.Text = "label4";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(175, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 12);
            this.label5.TabIndex = 21;
            this.label5.Text = "label5";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(219, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(38, 12);
            this.label6.TabIndex = 22;
            this.label6.Text = "label6";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(263, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(38, 12);
            this.label7.TabIndex = 23;
            this.label7.Text = "label7";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(307, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(38, 12);
            this.label8.TabIndex = 24;
            this.label8.Text = "label8";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(351, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(38, 12);
            this.label9.TabIndex = 25;
            this.label9.Text = "label9";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(395, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(44, 12);
            this.label10.TabIndex = 26;
            this.label10.Text = "label10";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(445, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(44, 12);
            this.label11.TabIndex = 27;
            this.label11.Text = "label11";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(495, 0);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(44, 12);
            this.label12.TabIndex = 28;
            this.label12.Text = "label12";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(545, 0);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(44, 12);
            this.label13.TabIndex = 29;
            this.label13.Text = "label13";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(595, 0);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(44, 12);
            this.label14.TabIndex = 30;
            this.label14.Text = "label14";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(645, 0);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(44, 12);
            this.label15.TabIndex = 31;
            this.label15.Text = "label15";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(695, 0);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(44, 12);
            this.label16.TabIndex = 32;
            this.label16.Text = "label16";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(745, 0);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(44, 12);
            this.label17.TabIndex = 33;
            this.label17.Text = "label17";
            // 
            // status_panel
            // 
            this.status_panel.Controls.Add(this.label1);
            this.status_panel.Controls.Add(this.label14);
            this.status_panel.Controls.Add(this.label17);
            this.status_panel.Controls.Add(this.label2);
            this.status_panel.Controls.Add(this.label16);
            this.status_panel.Controls.Add(this.label3);
            this.status_panel.Controls.Add(this.label15);
            this.status_panel.Controls.Add(this.label4);
            this.status_panel.Controls.Add(this.label5);
            this.status_panel.Controls.Add(this.label13);
            this.status_panel.Controls.Add(this.label6);
            this.status_panel.Controls.Add(this.label12);
            this.status_panel.Controls.Add(this.label7);
            this.status_panel.Controls.Add(this.label11);
            this.status_panel.Controls.Add(this.label8);
            this.status_panel.Controls.Add(this.label10);
            this.status_panel.Controls.Add(this.label9);
            this.status_panel.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.status_panel.Location = new System.Drawing.Point(0, 725);
            this.status_panel.Name = "status_panel";
            this.status_panel.Size = new System.Drawing.Size(1016, 12);
            this.status_panel.TabIndex = 0;
            // 
            // Attribute_panel
            // 
            this.Attribute_panel.Controls.Add(this.attribute_ObjectType);
            this.Attribute_panel.Controls.Add(this.label19);
            this.Attribute_panel.Controls.Add(this.CurrentTileInfo_Position);
            this.Attribute_panel.Controls.Add(this.attribute_index);
            this.Attribute_panel.Controls.Add(this.attribute_height);
            this.Attribute_panel.Controls.Add(this.label18);
            this.Attribute_panel.Controls.Add(this.attribute_move);
            this.Attribute_panel.Location = new System.Drawing.Point(1, 275);
            this.Attribute_panel.Margin = new System.Windows.Forms.Padding(0);
            this.Attribute_panel.Name = "Attribute_panel";
            this.Attribute_panel.Size = new System.Drawing.Size(191, 118);
            this.Attribute_panel.TabIndex = 0;
            // 
            // CurrentTileInfo_Position
            // 
            this.CurrentTileInfo_Position.AutoEllipsis = true;
            this.CurrentTileInfo_Position.AutoSize = true;
            this.CurrentTileInfo_Position.Location = new System.Drawing.Point(11, 10);
            this.CurrentTileInfo_Position.Name = "CurrentTileInfo_Position";
            this.CurrentTileInfo_Position.Size = new System.Drawing.Size(9, 12);
            this.CurrentTileInfo_Position.TabIndex = 4;
            this.CurrentTileInfo_Position.Text = " ";
            // 
            // attribute_index
            // 
            this.attribute_index.AutoSize = true;
            this.attribute_index.Location = new System.Drawing.Point(11, 10);
            this.attribute_index.Name = "attribute_index";
            this.attribute_index.Size = new System.Drawing.Size(9, 12);
            this.attribute_index.TabIndex = 3;
            this.attribute_index.Text = " ";
            // 
            // attribute_height
            // 
            this.attribute_height.ImeMode = System.Windows.Forms.ImeMode.Disable;
            this.attribute_height.Location = new System.Drawing.Point(52, 44);
            this.attribute_height.MaxLength = 1;
            this.attribute_height.Name = "attribute_height";
            this.attribute_height.ReadOnly = true;
            this.attribute_height.Size = new System.Drawing.Size(14, 21);
            this.attribute_height.TabIndex = 2;
            this.attribute_height.Text = " ";
            this.attribute_height.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.isNumber);
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(11, 44);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(39, 12);
            this.label18.TabIndex = 1;
            this.label18.Text = "height";
            // 
            // attribute_move
            // 
            this.attribute_move.AutoCheck = false;
            this.attribute_move.AutoSize = true;
            this.attribute_move.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.attribute_move.Location = new System.Drawing.Point(11, 25);
            this.attribute_move.Name = "attribute_move";
            this.attribute_move.Size = new System.Drawing.Size(55, 16);
            this.attribute_move.TabIndex = 0;
            this.attribute_move.Text = "move";
            this.attribute_move.UseVisualStyleBackColor = true;
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(9, 68);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(74, 12);
            this.label19.TabIndex = 5;
            this.label19.Text = "Object Type";
            // 
            // attribute_ObjectType
            // 
            this.attribute_ObjectType.AutoEllipsis = true;
            this.attribute_ObjectType.AutoSize = true;
            this.attribute_ObjectType.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.attribute_ObjectType.Location = new System.Drawing.Point(86, 68);
            this.attribute_ObjectType.Name = "attribute_ObjectType";
            this.attribute_ObjectType.Size = new System.Drawing.Size(11, 14);
            this.attribute_ObjectType.TabIndex = 6;
            this.attribute_ObjectType.Text = " ";
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1016, 737);
            this.Controls.Add(this.Attribute_panel);
            this.Controls.Add(this.status_panel);
            this.Controls.Add(this.magnification);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.layers);
            this.Controls.Add(this.contents);
            this.Controls.Add(this.minimap);
            this.Controls.Add(this.메뉴);
            this.Controls.Add(this.main_map_panel);
            this.MainMenuStrip = this.메뉴;
            this.MinimumSize = new System.Drawing.Size(800, 500);
            this.Name = "Main";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CSM Map Editor";
            this.Resize += new System.EventHandler(this.Main_Resize);
            this.메뉴.ResumeLayout(false);
            this.메뉴.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.minimap)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.status_panel.ResumeLayout(false);
            this.status_panel.PerformLayout();
            this.Attribute_panel.ResumeLayout(false);
            this.Attribute_panel.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip 메뉴;
        private System.Windows.Forms.ToolStripMenuItem menu_file;
        private System.Windows.Forms.ToolStripMenuItem menu_item_new;
        private System.Windows.Forms.ToolStripMenuItem menu_item_open;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem menu_item_save;
        private System.Windows.Forms.ToolStripMenuItem menu_item_save_as;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem menu_item_recent_file;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem menu_item_exit;
        private System.Windows.Forms.ToolStripMenuItem menu_edit;
        private System.Windows.Forms.ToolStripMenuItem menu_item_undo;
        private System.Windows.Forms.ToolStripMenuItem menu_item_redo;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripMenuItem menu_item_cut;
        private System.Windows.Forms.ToolStripMenuItem menu_item_copy;
        private System.Windows.Forms.ToolStripMenuItem menu_item_paste;
        private System.Windows.Forms.ToolStripMenuItem menu_item_delete;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem menu_item_select_all;
        private System.Windows.Forms.ToolStripMenuItem menu_view;
        private System.Windows.Forms.ToolStripMenuItem menu_tool;
        private System.Windows.Forms.ToolStripMenuItem menu_help;
        private System.Windows.Forms.ToolStripMenuItem menu_item_view_help;
        private System.Windows.Forms.ToolStripMenuItem menu_item_report_a_bug;
        private System.Windows.Forms.ToolStripMenuItem menu_item_info;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem menu_item_close;
        private System.Windows.Forms.ToolStripMenuItem menu_item_close_all;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
        private System.Windows.Forms.TreeView contents;

        private System.Windows.Forms.ComboBox layers;
        private System.Windows.Forms.Button button_load;
        private System.Windows.Forms.Button button_save;
        private System.Windows.Forms.Button button_new;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Panel main_map_panel;
        private System.Windows.Forms.ComboBox magnification;
        public System.Windows.Forms.PictureBox minimap;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Panel status_panel;
        private System.Windows.Forms.Panel Attribute_panel;
        private System.Windows.Forms.CheckBox attribute_move;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.TextBox attribute_height;
        private System.Windows.Forms.Label attribute_index;
        private System.Windows.Forms.Label CurrentTileInfo_Position;
        private System.Windows.Forms.Label attribute_ObjectType;
        private System.Windows.Forms.Label label19;

    }
}

