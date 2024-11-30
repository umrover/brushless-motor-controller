import numpy as np
import matplotlib.pyplot as plt

# Read the input file
filename = "example_out.txt"
data = np.loadtxt(filename)

# Extract relevant columns
sector = data[:, 0]          # Sector
valpha = data[:, 1]          # Valpha (alphaVoltage)
vbeta = data[:, 2]           # Vbeta (betaVoltage)
phase_a = data[:, 3]         # Duty cycle for Phase A
phase_b = data[:, 4]         # Duty cycle for Phase B
phase_c = data[:, 5]         # Duty cycle for Phase C
t1_values = data[:, 6]       # t1
t2_values = data[:, 7]       # t2
xyzs1 = data[:, 8]           # X
xyzs2 = data[:, 9]           # Y
xyzs3 = data[:, 10]          # Z

# Compute additional quantities
theta = np.arctan2(vbeta, valpha)  # Angle in radians
t1_t2_sum = t1_values + t2_values  # Sum of t1 and t2

# Generate indices for the x-axis
indices = np.arange(len(phase_a))

# Create subplots with shared x-axis
fig, axes = plt.subplots(6, 1, figsize=(14, 40), sharex=True)

# Plot 1: Duty cycles
axes[0].plot(indices, (phase_a / 100) - 0.5, label='Phase A', color='red', linewidth=2)
axes[0].plot(indices, (phase_b / 100) - 0.5, label='Phase B', color='blue', linewidth=2)
axes[0].plot(indices, (phase_c / 100) - 0.5, label='Phase C', color='green', linewidth=2)
axes[0].set_title("Duty Cycles for Phases A, B, and C", fontsize=16)
axes[0].set_ylabel("Duty Cycle", fontsize=14)
axes[0].grid(True)
axes[0].legend()

# Plot 2: Valpha and Vbeta over time
axes[1].plot(indices, valpha, label='$V_{\\alpha}$', color='magenta', linewidth=2)
axes[1].plot(indices, vbeta, label='$V_{\\beta}$', color='cyan', linewidth=2)
axes[1].set_title("$V_{\\alpha}$ and $V_{\\beta}$ over Time", fontsize=16)
axes[1].set_ylabel("Voltage", fontsize=14)
axes[1].grid(True)
axes[1].legend()

# Plot 3: Theta over time
axes[2].plot(indices, np.degrees(theta), label='$\\theta$ (Angle)', color='orange', linewidth=2)
axes[2].set_title("Angle ($\\theta$) of the Vector Over Time", fontsize=16)
axes[2].set_ylabel("Angle (Degrees)", fontsize=14)
axes[2].grid(True)
axes[2].legend()

# Plot 4: Sector over time
axes[3].step(indices, sector, label='Sector', color='teal', linewidth=2, where='post')
axes[3].set_title("Sector Over Time", fontsize=16)
axes[3].set_ylabel("Sector", fontsize=14)
axes[3].grid(True)
axes[3].legend()

# Plot 5: XYZs
axes[4].plot(indices, xyzs1, label='X', color='forestgreen', linewidth=2)
axes[4].plot(indices, xyzs2, label='Y', color='crimson', linewidth=2)
axes[4].plot(indices, xyzs3, label='Z', color='royalblue', linewidth=2)
axes[4].set_title("XYZs Over Time", fontsize=16)
axes[4].set_ylabel("XYZs", fontsize=14)
axes[4].grid(True)
axes[4].legend()

# Plot 6: t1, t2, and their sum
axes[5].plot(indices, t1_values, label='t1', color='darkred', linewidth=2)
axes[5].plot(indices, t2_values, label='t2', color='darkgreen', linewidth=2)
axes[5].plot(indices, t1_t2_sum, label='t1 + t2', color='darkblue', linewidth=2, linestyle='--')
axes[5].set_title("t1, t2, and their Sum Over Time", fontsize=16)
axes[5].set_xlabel("Index", fontsize=14)
axes[5].set_ylabel("Time (t1, t2, Sum)", fontsize=14)
axes[5].grid(True)
axes[5].legend()

# Adjust layout and show all plots
plt.tight_layout()
plt.show()
