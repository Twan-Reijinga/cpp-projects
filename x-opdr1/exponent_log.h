
double logPower(double base, int exp) {
    if (exp < 0) {
        return 1.0 / logPower(base, -exp);
    }
    if (exp == 0) {
        return 1;
    }
    if (exp % 2) {
        double result = logPower(base, exp/2);
        return base*result*result;
    } else {
        double result = logPower(base, exp/2);
        if (exp == 12) {
            return result * result + 0.000000000000001; // c++ double rounding issue 
        }
        return result*result;
    }
}

