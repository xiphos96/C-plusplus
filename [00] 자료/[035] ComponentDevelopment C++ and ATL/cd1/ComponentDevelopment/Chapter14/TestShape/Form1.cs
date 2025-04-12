using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace TestShape
{
	/// <summary>
	/// Form1�� ���� ��� �����Դϴ�.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private AxShape.AxCShape axCShape1;
		private System.Windows.Forms.ComboBox cboType;
		private System.Windows.Forms.Label lblMessage;
		private System.Windows.Forms.Button btnChange;
		private System.Windows.Forms.Button btnShapeType;
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public Form1()
		{
			//
			// Windows Form �����̳� ������ �ʿ��մϴ�.
			//
			InitializeComponent();

			//
			// TODO: InitializeComponent�� ȣ���� ���� ������ �ڵ带 �߰��մϴ�.
			//
		}

		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form �����̳ʿ��� ������ �ڵ�
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�.
		/// �� �޼����� ������ �ڵ� ������� �������� ���ʽÿ�.
		/// </summary>
		private void InitializeComponent()
		{
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(Form1));
			this.axCShape1 = new AxShape.AxCShape();
			this.cboType = new System.Windows.Forms.ComboBox();
			this.btnChange = new System.Windows.Forms.Button();
			this.lblMessage = new System.Windows.Forms.Label();
			this.btnShapeType = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.axCShape1)).BeginInit();
			this.SuspendLayout();
			// 
			// axCShape1
			// 
			this.axCShape1.Enabled = true;
			this.axCShape1.Location = new System.Drawing.Point(40, 48);
			this.axCShape1.Name = "axCShape1";
			this.axCShape1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axCShape1.OcxState")));
			this.axCShape1.Size = new System.Drawing.Size(232, 200);
			this.axCShape1.TabIndex = 0;
			this.axCShape1.ClickOut += new AxShape._IShapeEvents_ClickOutEventHandler(this.OnClickOut);
			this.axCShape1.ClickIn += new AxShape._IShapeEvents_ClickInEventHandler(this.OnClickIn);
			// 
			// cboType
			// 
			this.cboType.Location = new System.Drawing.Point(320, 56);
			this.cboType.Name = "cboType";
			this.cboType.Size = new System.Drawing.Size(160, 20);
			this.cboType.TabIndex = 1;
			this.cboType.Text = "comboBox1";
			// 
			// btnChange
			// 
			this.btnChange.Location = new System.Drawing.Point(328, 208);
			this.btnChange.Name = "btnChange";
			this.btnChange.Size = new System.Drawing.Size(144, 23);
			this.btnChange.TabIndex = 2;
			this.btnChange.Text = "ChangeShape �޼���";
			this.btnChange.Click += new System.EventHandler(this.btnChange_Click);
			// 
			// lblMessage
			// 
			this.lblMessage.Location = new System.Drawing.Point(40, 280);
			this.lblMessage.Name = "lblMessage";
			this.lblMessage.Size = new System.Drawing.Size(440, 24);
			this.lblMessage.TabIndex = 3;
			this.lblMessage.Text = "�̺�Ʈ";
			// 
			// btnShapeType
			// 
			this.btnShapeType.Location = new System.Drawing.Point(328, 136);
			this.btnShapeType.Name = "btnShapeType";
			this.btnShapeType.Size = new System.Drawing.Size(144, 23);
			this.btnShapeType.TabIndex = 4;
			this.btnShapeType.Text = "ShapeType �Ӽ�";
			this.btnShapeType.Click += new System.EventHandler(this.btnShapeType_Click);
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(536, 333);
			this.Controls.Add(this.btnShapeType);
			this.Controls.Add(this.lblMessage);
			this.Controls.Add(this.btnChange);
			this.Controls.Add(this.cboType);
			this.Controls.Add(this.axCShape1);
			this.Name = "Form1";
			this.Text = "Shape ��Ʈ�� �׽�Ʈ";
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.axCShape1)).EndInit();
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// �ش� ���� ���α׷��� �� �������Դϴ�.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		private void Form1_Load(object sender, System.EventArgs e) {
			cboType.Items.Add("�簢��");
			cboType.Items.Add("����");
			cboType.Items.Add("�ﰢ��");
			cboType.SelectedIndex = axCShape1.ShapeType;
		}

		private void OnClickIn(object sender, AxShape._IShapeEvents_ClickInEvent e) {
			lblMessage.Text = string.Format("Click In : ({0}, {1})", e.x, e.y);
		}

		private void OnClickOut(object sender, AxShape._IShapeEvents_ClickOutEvent e) {
			lblMessage.Text = string.Format("Click Out : ({0}, {1})", e.x, e.y);
		}

		private void btnShapeType_Click(object sender, System.EventArgs e) {
			axCShape1.ShapeType = (short)cboType.SelectedIndex;
		}

		private void btnChange_Click(object sender, System.EventArgs e) {
			axCShape1.ChangeShape((short)cboType.SelectedIndex);
		}
	}
}
