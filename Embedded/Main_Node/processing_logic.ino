float expectedPower(float light, float temp, float humidity) {
    // Replace with trained coefficients
    return (0.5 * light) + (0.2 * temp) + (0.1 * humidity);
}

float computeResidual(float actual, float expected) {
    return actual - expected;
}