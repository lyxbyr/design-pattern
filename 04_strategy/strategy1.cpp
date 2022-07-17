enum TaxBase { CN_Tax, US_Tax, DE_Tax, FR_Tax };

class SalesOrder {
  TaxBase tax;

 public:
  double CalculateTax() {
    if (tax == CN_Tax) {
    } else if () {
    }
  }
};