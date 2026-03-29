import numpy as np

def compute_features(power, light, temp, humidity):
    efficiency = power / (light + 1e-6)
    return {
        "efficiency": efficiency,
        "power": power,
        "light": light,
        "temp": temp,
        "humidity": humidity
    }