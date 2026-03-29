import numpy as np
from sklearn.linear_model import LinearRegression
import json

# Dummy data (replace later)
X = np.random.rand(100, 3)  # light, temp, humidity
y = np.random.rand(100)     # power

model = LinearRegression()
model.fit(X, y)

params = {
    "coefficients": model.coef_.tolist(),
    "intercept": model.intercept_
}

with open("model_outputs/regression_params.json", "w") as f:
    json.dump(params, f)