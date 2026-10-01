namespace Pizza_Project
{
    partial class frmPizzaProjectv1
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
            this.lblTitle = new System.Windows.Forms.Label();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.rbMedium = new System.Windows.Forms.RadioButton();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.gbSize = new System.Windows.Forms.GroupBox();
            this.rbThin = new System.Windows.Forms.RadioButton();
            this.rbThick = new System.Windows.Forms.RadioButton();
            this.gbCrustType = new System.Windows.Forms.GroupBox();
            this.chbExtraChees = new System.Windows.Forms.CheckBox();
            this.chbMushrooms = new System.Windows.Forms.CheckBox();
            this.chbTomatoes = new System.Windows.Forms.CheckBox();
            this.chbGreenPeppers = new System.Windows.Forms.CheckBox();
            this.chbOlives = new System.Windows.Forms.CheckBox();
            this.chbOnion = new System.Windows.Forms.CheckBox();
            this.gbToppings = new System.Windows.Forms.GroupBox();
            this.rbEatIn = new System.Windows.Forms.RadioButton();
            this.rbTakeOut = new System.Windows.Forms.RadioButton();
            this.gbWhereToEat = new System.Windows.Forms.GroupBox();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.lblSize = new System.Windows.Forms.Label();
            this.lblSize2 = new System.Windows.Forms.Label();
            this.lblToppings = new System.Windows.Forms.Label();
            this.lblToppings2 = new System.Windows.Forms.Label();
            this.lblCrustType = new System.Windows.Forms.Label();
            this.lblCrustType2 = new System.Windows.Forms.Label();
            this.lblWheretoEat = new System.Windows.Forms.Label();
            this.lblTotalPrice = new System.Windows.Forms.Label();
            this.lblTotalPrice2 = new System.Windows.Forms.Label();
            this.lblWhereToEat2 = new System.Windows.Forms.Label();
            this.btnResetForm = new System.Windows.Forms.Button();
            this.gbOrderSummary = new System.Windows.Forms.GroupBox();
            this.gbSize.SuspendLayout();
            this.gbCrustType.SuspendLayout();
            this.gbToppings.SuspendLayout();
            this.gbWhereToEat.SuspendLayout();
            this.gbOrderSummary.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.ForeColor = System.Drawing.Color.Red;
            this.lblTitle.Location = new System.Drawing.Point(232, 17);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(531, 73);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Make Your Pizza";
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Location = new System.Drawing.Point(39, 28);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(50, 17);
            this.rbSmall.TabIndex = 1;
            this.rbSmall.Tag = "20";
            this.rbSmall.Text = "Small";
            this.rbSmall.UseVisualStyleBackColor = true;
            this.rbSmall.CheckedChanged += new System.EventHandler(this.rbSmall_CheckedChanged);
            // 
            // rbMedium
            // 
            this.rbMedium.AutoSize = true;
            this.rbMedium.Checked = true;
            this.rbMedium.Location = new System.Drawing.Point(39, 72);
            this.rbMedium.Name = "rbMedium";
            this.rbMedium.Size = new System.Drawing.Size(62, 17);
            this.rbMedium.TabIndex = 2;
            this.rbMedium.TabStop = true;
            this.rbMedium.Tag = "30";
            this.rbMedium.Text = "Medium";
            this.rbMedium.UseVisualStyleBackColor = true;
            this.rbMedium.CheckedChanged += new System.EventHandler(this.rbMedium_CheckedChanged);
            // 
            // rbLarge
            // 
            this.rbLarge.AutoSize = true;
            this.rbLarge.Location = new System.Drawing.Point(39, 116);
            this.rbLarge.Name = "rbLarge";
            this.rbLarge.Size = new System.Drawing.Size(52, 17);
            this.rbLarge.TabIndex = 3;
            this.rbLarge.Tag = "40";
            this.rbLarge.Text = "Large";
            this.rbLarge.UseVisualStyleBackColor = true;
            this.rbLarge.CheckedChanged += new System.EventHandler(this.rbLarge_CheckedChanged);
            // 
            // gbSize
            // 
            this.gbSize.Controls.Add(this.rbLarge);
            this.gbSize.Controls.Add(this.rbMedium);
            this.gbSize.Controls.Add(this.rbSmall);
            this.gbSize.Location = new System.Drawing.Point(71, 125);
            this.gbSize.Name = "gbSize";
            this.gbSize.Size = new System.Drawing.Size(140, 168);
            this.gbSize.TabIndex = 4;
            this.gbSize.TabStop = false;
            this.gbSize.Text = "Size";
            // 
            // rbThin
            // 
            this.rbThin.AutoSize = true;
            this.rbThin.Checked = true;
            this.rbThin.Location = new System.Drawing.Point(15, 28);
            this.rbThin.Name = "rbThin";
            this.rbThin.Size = new System.Drawing.Size(73, 17);
            this.rbThin.TabIndex = 5;
            this.rbThin.TabStop = true;
            this.rbThin.Tag = "0";
            this.rbThin.Text = "Thin Crust";
            this.rbThin.UseVisualStyleBackColor = true;
            this.rbThin.CheckedChanged += new System.EventHandler(this.rbThin_CheckedChanged);
            // 
            // rbThick
            // 
            this.rbThick.AutoSize = true;
            this.rbThick.Location = new System.Drawing.Point(15, 68);
            this.rbThick.Name = "rbThick";
            this.rbThick.Size = new System.Drawing.Size(79, 17);
            this.rbThick.TabIndex = 6;
            this.rbThick.Tag = "10";
            this.rbThick.Text = "Thick Crust";
            this.rbThick.UseVisualStyleBackColor = true;
            this.rbThick.CheckedChanged += new System.EventHandler(this.rbThick_CheckedChanged);
            // 
            // gbCrustType
            // 
            this.gbCrustType.Controls.Add(this.rbThick);
            this.gbCrustType.Controls.Add(this.rbThin);
            this.gbCrustType.Location = new System.Drawing.Point(71, 347);
            this.gbCrustType.Name = "gbCrustType";
            this.gbCrustType.Size = new System.Drawing.Size(138, 113);
            this.gbCrustType.TabIndex = 7;
            this.gbCrustType.TabStop = false;
            this.gbCrustType.Text = "Crust Type";
            // 
            // chbExtraChees
            // 
            this.chbExtraChees.AutoSize = true;
            this.chbExtraChees.Location = new System.Drawing.Point(27, 40);
            this.chbExtraChees.Name = "chbExtraChees";
            this.chbExtraChees.Size = new System.Drawing.Size(83, 17);
            this.chbExtraChees.TabIndex = 8;
            this.chbExtraChees.Tag = "5";
            this.chbExtraChees.Text = "Extra Chees";
            this.chbExtraChees.UseVisualStyleBackColor = true;
            this.chbExtraChees.CheckedChanged += new System.EventHandler(this.chbExtraChees_CheckedChanged);
            // 
            // chbMushrooms
            // 
            this.chbMushrooms.AutoSize = true;
            this.chbMushrooms.Location = new System.Drawing.Point(27, 74);
            this.chbMushrooms.Name = "chbMushrooms";
            this.chbMushrooms.Size = new System.Drawing.Size(80, 17);
            this.chbMushrooms.TabIndex = 9;
            this.chbMushrooms.Tag = "5";
            this.chbMushrooms.Text = "Mushrooms";
            this.chbMushrooms.UseVisualStyleBackColor = true;
            this.chbMushrooms.CheckedChanged += new System.EventHandler(this.chbMushrooms_CheckedChanged);
            // 
            // chbTomatoes
            // 
            this.chbTomatoes.AutoSize = true;
            this.chbTomatoes.Location = new System.Drawing.Point(27, 108);
            this.chbTomatoes.Name = "chbTomatoes";
            this.chbTomatoes.Size = new System.Drawing.Size(73, 17);
            this.chbTomatoes.TabIndex = 10;
            this.chbTomatoes.Tag = "5";
            this.chbTomatoes.Text = "Tomatoes";
            this.chbTomatoes.UseVisualStyleBackColor = true;
            this.chbTomatoes.CheckedChanged += new System.EventHandler(this.chbTomatoes_CheckedChanged);
            // 
            // chbGreenPeppers
            // 
            this.chbGreenPeppers.AutoSize = true;
            this.chbGreenPeppers.Location = new System.Drawing.Point(159, 107);
            this.chbGreenPeppers.Name = "chbGreenPeppers";
            this.chbGreenPeppers.Size = new System.Drawing.Size(97, 17);
            this.chbGreenPeppers.TabIndex = 13;
            this.chbGreenPeppers.Tag = "5";
            this.chbGreenPeppers.Text = "Green Peppers";
            this.chbGreenPeppers.UseVisualStyleBackColor = true;
            this.chbGreenPeppers.CheckedChanged += new System.EventHandler(this.chbGreenPeppers_CheckedChanged);
            // 
            // chbOlives
            // 
            this.chbOlives.AutoSize = true;
            this.chbOlives.Location = new System.Drawing.Point(159, 73);
            this.chbOlives.Name = "chbOlives";
            this.chbOlives.Size = new System.Drawing.Size(55, 17);
            this.chbOlives.TabIndex = 12;
            this.chbOlives.Tag = "5";
            this.chbOlives.Text = "Olives";
            this.chbOlives.UseVisualStyleBackColor = true;
            this.chbOlives.CheckedChanged += new System.EventHandler(this.chbOlives_CheckedChanged);
            // 
            // chbOnion
            // 
            this.chbOnion.AutoSize = true;
            this.chbOnion.Location = new System.Drawing.Point(159, 39);
            this.chbOnion.Name = "chbOnion";
            this.chbOnion.Size = new System.Drawing.Size(54, 17);
            this.chbOnion.TabIndex = 11;
            this.chbOnion.Tag = "5";
            this.chbOnion.Text = "Onion";
            this.chbOnion.UseVisualStyleBackColor = true;
            this.chbOnion.CheckedChanged += new System.EventHandler(this.chbOnion_CheckedChanged);
            // 
            // gbToppings
            // 
            this.gbToppings.Controls.Add(this.chbGreenPeppers);
            this.gbToppings.Controls.Add(this.chbOlives);
            this.gbToppings.Controls.Add(this.chbOnion);
            this.gbToppings.Controls.Add(this.chbTomatoes);
            this.gbToppings.Controls.Add(this.chbMushrooms);
            this.gbToppings.Controls.Add(this.chbExtraChees);
            this.gbToppings.Location = new System.Drawing.Point(329, 125);
            this.gbToppings.Name = "gbToppings";
            this.gbToppings.Size = new System.Drawing.Size(279, 168);
            this.gbToppings.TabIndex = 14;
            this.gbToppings.TabStop = false;
            this.gbToppings.Text = "Toppings";
            // 
            // rbEatIn
            // 
            this.rbEatIn.AutoSize = true;
            this.rbEatIn.Checked = true;
            this.rbEatIn.Location = new System.Drawing.Point(21, 42);
            this.rbEatIn.Name = "rbEatIn";
            this.rbEatIn.Size = new System.Drawing.Size(53, 17);
            this.rbEatIn.TabIndex = 15;
            this.rbEatIn.TabStop = true;
            this.rbEatIn.Text = "Eat In";
            this.rbEatIn.UseVisualStyleBackColor = true;
            this.rbEatIn.CheckedChanged += new System.EventHandler(this.rbEatIn_CheckedChanged);
            // 
            // rbTakeOut
            // 
            this.rbTakeOut.AutoSize = true;
            this.rbTakeOut.Location = new System.Drawing.Point(113, 42);
            this.rbTakeOut.Name = "rbTakeOut";
            this.rbTakeOut.Size = new System.Drawing.Size(70, 17);
            this.rbTakeOut.TabIndex = 16;
            this.rbTakeOut.Text = "Take Out";
            this.rbTakeOut.UseVisualStyleBackColor = true;
            this.rbTakeOut.CheckedChanged += new System.EventHandler(this.rbTakeOut_CheckedChanged);
            // 
            // gbWhereToEat
            // 
            this.gbWhereToEat.Controls.Add(this.rbTakeOut);
            this.gbWhereToEat.Controls.Add(this.rbEatIn);
            this.gbWhereToEat.Location = new System.Drawing.Point(329, 347);
            this.gbWhereToEat.Name = "gbWhereToEat";
            this.gbWhereToEat.Size = new System.Drawing.Size(279, 92);
            this.gbWhereToEat.TabIndex = 17;
            this.gbWhereToEat.TabStop = false;
            this.gbWhereToEat.Text = "Where To Eat";
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.Location = new System.Drawing.Point(313, 488);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(90, 36);
            this.btnOrderPizza.TabIndex = 18;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = true;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // lblSize
            // 
            this.lblSize.AutoSize = true;
            this.lblSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSize.Location = new System.Drawing.Point(28, 41);
            this.lblSize.Name = "lblSize";
            this.lblSize.Size = new System.Drawing.Size(35, 13);
            this.lblSize.TabIndex = 21;
            this.lblSize.Text = "Size:";
            // 
            // lblSize2
            // 
            this.lblSize2.AutoSize = true;
            this.lblSize2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSize2.Location = new System.Drawing.Point(67, 41);
            this.lblSize2.Name = "lblSize2";
            this.lblSize2.Size = new System.Drawing.Size(44, 13);
            this.lblSize2.TabIndex = 22;
            this.lblSize2.Text = "Medium";
            // 
            // lblToppings
            // 
            this.lblToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblToppings.Location = new System.Drawing.Point(28, 81);
            this.lblToppings.Name = "lblToppings";
            this.lblToppings.Size = new System.Drawing.Size(67, 13);
            this.lblToppings.TabIndex = 23;
            this.lblToppings.Text = "Toppings: ";
            // 
            // lblToppings2
            // 
            this.lblToppings2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblToppings2.Location = new System.Drawing.Point(54, 104);
            this.lblToppings2.Name = "lblToppings2";
            this.lblToppings2.Size = new System.Drawing.Size(183, 53);
            this.lblToppings2.TabIndex = 24;
            this.lblToppings2.Text = "No Toppings.";
            // 
            // lblCrustType
            // 
            this.lblCrustType.AutoSize = true;
            this.lblCrustType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCrustType.Location = new System.Drawing.Point(28, 158);
            this.lblCrustType.Name = "lblCrustType";
            this.lblCrustType.Size = new System.Drawing.Size(72, 13);
            this.lblCrustType.TabIndex = 25;
            this.lblCrustType.Text = "Crust Type:";
            // 
            // lblCrustType2
            // 
            this.lblCrustType2.AutoSize = true;
            this.lblCrustType2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCrustType2.Location = new System.Drawing.Point(106, 158);
            this.lblCrustType2.Name = "lblCrustType2";
            this.lblCrustType2.Size = new System.Drawing.Size(55, 13);
            this.lblCrustType2.TabIndex = 26;
            this.lblCrustType2.Text = "Thin Crust";
            // 
            // lblWheretoEat
            // 
            this.lblWheretoEat.AutoSize = true;
            this.lblWheretoEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWheretoEat.Location = new System.Drawing.Point(28, 184);
            this.lblWheretoEat.Name = "lblWheretoEat";
            this.lblWheretoEat.Size = new System.Drawing.Size(90, 13);
            this.lblWheretoEat.TabIndex = 27;
            this.lblWheretoEat.Text = "Where to Eat: ";
            // 
            // lblTotalPrice
            // 
            this.lblTotalPrice.AutoSize = true;
            this.lblTotalPrice.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTotalPrice.Location = new System.Drawing.Point(28, 282);
            this.lblTotalPrice.Name = "lblTotalPrice";
            this.lblTotalPrice.Size = new System.Drawing.Size(73, 13);
            this.lblTotalPrice.TabIndex = 29;
            this.lblTotalPrice.Text = "Total Price:";
            // 
            // lblTotalPrice2
            // 
            this.lblTotalPrice2.AutoSize = true;
            this.lblTotalPrice2.Font = new System.Drawing.Font("Juice ITC", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTotalPrice2.ForeColor = System.Drawing.Color.LimeGreen;
            this.lblTotalPrice2.Location = new System.Drawing.Point(97, 312);
            this.lblTotalPrice2.Name = "lblTotalPrice2";
            this.lblTotalPrice2.Size = new System.Drawing.Size(76, 72);
            this.lblTotalPrice2.TabIndex = 30;
            this.lblTotalPrice2.Text = "$0";
            // 
            // lblWhereToEat2
            // 
            this.lblWhereToEat2.AutoSize = true;
            this.lblWhereToEat2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWhereToEat2.Location = new System.Drawing.Point(106, 206);
            this.lblWhereToEat2.Name = "lblWhereToEat2";
            this.lblWhereToEat2.Size = new System.Drawing.Size(35, 13);
            this.lblWhereToEat2.TabIndex = 31;
            this.lblWhereToEat2.Text = "Eat In";
            // 
            // btnResetForm
            // 
            this.btnResetForm.Location = new System.Drawing.Point(507, 488);
            this.btnResetForm.Name = "btnResetForm";
            this.btnResetForm.Size = new System.Drawing.Size(90, 36);
            this.btnResetForm.TabIndex = 32;
            this.btnResetForm.Text = "Reset Form";
            this.btnResetForm.UseVisualStyleBackColor = true;
            this.btnResetForm.Click += new System.EventHandler(this.btnResetForm_Click);
            // 
            // gbOrderSummary
            // 
            this.gbOrderSummary.Controls.Add(this.lblTotalPrice2);
            this.gbOrderSummary.Controls.Add(this.lblSize);
            this.gbOrderSummary.Controls.Add(this.lblWhereToEat2);
            this.gbOrderSummary.Controls.Add(this.lblSize2);
            this.gbOrderSummary.Controls.Add(this.lblToppings);
            this.gbOrderSummary.Controls.Add(this.lblTotalPrice);
            this.gbOrderSummary.Controls.Add(this.lblToppings2);
            this.gbOrderSummary.Controls.Add(this.lblWheretoEat);
            this.gbOrderSummary.Controls.Add(this.lblCrustType);
            this.gbOrderSummary.Controls.Add(this.lblCrustType2);
            this.gbOrderSummary.Location = new System.Drawing.Point(735, 125);
            this.gbOrderSummary.Name = "gbOrderSummary";
            this.gbOrderSummary.Size = new System.Drawing.Size(243, 402);
            this.gbOrderSummary.TabIndex = 33;
            this.gbOrderSummary.TabStop = false;
            this.gbOrderSummary.Text = "Order Summary";
            // 
            // frmPizzaProjectv1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1052, 618);
            this.Controls.Add(this.gbOrderSummary);
            this.Controls.Add(this.btnResetForm);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.gbWhereToEat);
            this.Controls.Add(this.gbToppings);
            this.Controls.Add(this.gbCrustType);
            this.Controls.Add(this.gbSize);
            this.Controls.Add(this.lblTitle);
            this.Name = "frmPizzaProjectv1";
            this.Text = "Pizza Order";
            this.Load += new System.EventHandler(this.frmPizzaProjectv1_Load);
            this.gbSize.ResumeLayout(false);
            this.gbSize.PerformLayout();
            this.gbCrustType.ResumeLayout(false);
            this.gbCrustType.PerformLayout();
            this.gbToppings.ResumeLayout(false);
            this.gbToppings.PerformLayout();
            this.gbWhereToEat.ResumeLayout(false);
            this.gbWhereToEat.PerformLayout();
            this.gbOrderSummary.ResumeLayout(false);
            this.gbOrderSummary.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.RadioButton rbMedium;
        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.GroupBox gbSize;
        private System.Windows.Forms.RadioButton rbThin;
        private System.Windows.Forms.RadioButton rbThick;
        private System.Windows.Forms.GroupBox gbCrustType;
        private System.Windows.Forms.CheckBox chbExtraChees;
        private System.Windows.Forms.CheckBox chbMushrooms;
        private System.Windows.Forms.CheckBox chbTomatoes;
        private System.Windows.Forms.CheckBox chbGreenPeppers;
        private System.Windows.Forms.CheckBox chbOlives;
        private System.Windows.Forms.CheckBox chbOnion;
        private System.Windows.Forms.GroupBox gbToppings;
        private System.Windows.Forms.RadioButton rbEatIn;
        private System.Windows.Forms.RadioButton rbTakeOut;
        private System.Windows.Forms.GroupBox gbWhereToEat;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Label lblSize;
        private System.Windows.Forms.Label lblSize2;
        private System.Windows.Forms.Label lblToppings;
        private System.Windows.Forms.Label lblToppings2;
        private System.Windows.Forms.Label lblCrustType;
        private System.Windows.Forms.Label lblCrustType2;
        private System.Windows.Forms.Label lblWheretoEat;
        private System.Windows.Forms.Label lblTotalPrice;
        private System.Windows.Forms.Label lblTotalPrice2;
        private System.Windows.Forms.Label lblWhereToEat2;
        private System.Windows.Forms.Button btnResetForm;
        private System.Windows.Forms.GroupBox gbOrderSummary;
    }
}