using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pizza_Project
{
    public partial class frmPizzaProjectv1 : Form
    {
        public frmPizzaProjectv1()
        {
            InitializeComponent();
        }

        float GetSizePrice()
        {
            if (rbSmall.Checked)
                return Convert.ToSingle(rbSmall.Tag);
            else if (rbMedium.Checked)
                return Convert.ToSingle(rbMedium.Tag);
            return Convert.ToSingle(rbLarge.Tag);
        }

        float GetCrustTypePrice()
        {
            if (rbThin.Checked)
                return Convert.ToSingle(rbThin.Tag);
            return Convert.ToSingle(rbThick.Tag);
        }

        float GetToppingsPrice()
        {
            float ToppingsPrice = 0;

            if (chbExtraChees.Checked)
                ToppingsPrice += Convert.ToSingle(chbExtraChees.Tag);
            if (chbMushrooms.Checked)
                ToppingsPrice += Convert.ToSingle(chbMushrooms.Tag);
            if (chbTomatoes.Checked)
                ToppingsPrice += Convert.ToSingle(chbTomatoes.Tag);
            if (chbOnion.Checked)
                ToppingsPrice += Convert.ToSingle(chbOnion.Tag);
            if (chbOlives.Checked)
                ToppingsPrice += Convert.ToSingle(chbOlives.Tag);
            if (chbGreenPeppers.Checked)
                ToppingsPrice += Convert.ToSingle(chbGreenPeppers.Tag);

            return ToppingsPrice;
        }

        float CalculateTotalPrice()
        {
            return GetSizePrice() + GetCrustTypePrice() + GetToppingsPrice();
        }

        void UpdateTotalPrice()
        {
            lblTotalPrice2.Text = "$" + CalculateTotalPrice().ToString();
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked)
                lblSize2.Text = "Small";
            else if (rbMedium.Checked)
                lblSize2.Text = "Medium";
            else
                lblSize2.Text = "Large";
        }

        void UpdateCrust()
        {
            UpdateTotalPrice();

            if (rbThin.Checked)
                lblCrustType2.Text = "Thin Crust";
            else
                lblCrustType2.Text = "Thick Crust";
        }

        void UpdateToppings()
        {
            UpdateTotalPrice();

            string sToppings = "";

            if (chbExtraChees.Checked)
                sToppings = "Extra Chees";
            if (chbMushrooms.Checked)
                sToppings += ", Mushrooms";
            if (chbTomatoes.Checked)
                sToppings += ", Tomatoes";
            if (chbOnion.Checked)
                sToppings += ", Onion";
            if (chbOlives.Checked)
                sToppings += ", Olives";
            if (chbGreenPeppers.Checked)
                sToppings += ", Green Peppers";
            
            if (sToppings.StartsWith(","))
                sToppings = sToppings.Substring(1, sToppings.Length - 1).Trim();
            if (sToppings == "")
                sToppings = "No Toppings";

            lblToppings2.Text = sToppings;
        }

        void UpdateWhereToEat()
        {
            if (rbEatIn.Checked)
                lblWhereToEat2.Text = "Eat In";
            else
                lblWhereToEat2.Text = "Take Out";

        }

        private void frmPizzaProjectv1_Load(object sender, EventArgs e)
        {
            UpdateSize();
            UpdateCrust();
            UpdateToppings();
            UpdateWhereToEat();
        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbMedium_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbThin_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbThick_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void chbExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chbMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chbTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chbOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chbOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chbGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void rbTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                gbSize.Enabled = false;
                gbCrustType.Enabled = false;
                gbToppings.Enabled = false;
                gbWhereToEat.Enabled = false;
                btnOrderPizza.Enabled = false;
            }
        }

        void ResetForm()
        {
            gbSize.Enabled = true;
            rbSmall.Checked = false;
            rbMedium.Checked = true;
            rbLarge.Checked = false;

            gbCrustType.Enabled = true;
            rbThin.Checked = true;
            rbThick.Checked = false;

            gbToppings.Enabled = true;
            chbExtraChees.Checked = false;
            chbMushrooms.Checked = false;
            chbTomatoes.Checked = false;
            chbOnion.Checked = false;
            chbOlives.Checked = false;
            chbGreenPeppers.Checked = false;

            gbWhereToEat.Enabled = true;
            rbEatIn.Checked = true;
            rbTakeOut.Checked = false;
        }

        private void btnResetForm_Click(object sender, EventArgs e)
        {
            ResetForm();
        }
    }
}
