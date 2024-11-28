import numpy as np
import matplotlib.pyplot as plt

# Read the input file
filename = "example_out.txt"
vrefs_valpha = []
vrefs_vbeta = []

# Parse the file to extract Vrefs
with open(filename, "r") as file:
    lines = file.readlines()
    for line in lines:
        if line.startswith("VREFs"):
            parts = line.split()
            vrefs_valpha.append(float(parts[1]))  # Valpha of Vrefs
            vrefs_vbeta.append(float(parts[2]))  # Vbeta of Vrefs

# Convert Vrefs to numpy arrays
vrefs_valpha = np.array(vrefs_valpha)
vrefs_vbeta = np.array(vrefs_vbeta)

# Extract remaining data
data = [line for line in lines if not line.startswith("VREFs")]
data = np.loadtxt(data)

sector = data[:, 0]    # Sector
valpha = data[:, 1]    # Valpha
vbeta = data[:, 2]     # Vbeta
phase_a = data[:, 3]   # Duty cycle for Phase A
phase_b = data[:, 4]   # Duty cycle for Phase B
phase_c = data[:, 5]   # Duty cycle for Phase C

# Compute theta (angle of the vector)
theta = np.arctan2(vbeta, valpha)  # Angle in radians

# Generate indices for the x-axis
indices = np.arange(len(phase_a))

# Create the figure
fig = plt.figure(figsize=(14, 24))

# Plot 1: Duty cycles
ax1 = plt.subplot(6, 1, 1)
ax1.plot(indices[0:10000] - 0.5, (phase_a / 100)[0:10000] - 0.5, label='Phase A', color='red', linewidth=2)
ax1.plot(indices[0:10000] - 0.5, (phase_b / 100)[0:10000] - 0.5, label='Phase B', color='blue', linewidth=2)
ax1.plot(indices[0:10000] - 0.5, (phase_c / 100)[0:10000] - 0.5, label='Phase C', color='green', linewidth=2)
ax1.set_title("Duty Cycles for Phases A, B, and C", fontsize=16)
ax1.set_ylabel("Duty Cycle", fontsize=14)
ax1.grid(True)
ax1.legend()

# Plot 2: Valpha and Vbeta over time
ax2 = plt.subplot(6, 1, 2, sharex=ax1)
ax2.plot(indices[0:10000], valpha[0:10000], label='$V_{\\alpha}$', color='magenta', linewidth=2)
ax2.plot(indices[0:10000], vbeta[0:10000], label='$V_{\\beta}$', color='cyan', linewidth=2)
ax2.set_title("$V_{\\alpha}$ and $V_{\\beta}$ over Time", fontsize=16)
ax2.set_ylabel("Voltage", fontsize=14)
ax2.grid(True)
ax2.legend()

# Plot 3: Cartesian plot of Vrefs
ax3 = plt.subplot(6, 1, 3)
ax3.plot(vrefs_valpha, vrefs_vbeta, label='Vrefs Trajectory', color='purple', linewidth=2)
ax3.scatter(vrefs_valpha, vrefs_vbeta, color='purple', s=5, alpha=0.6)
ax3.set_title("$V_{\\alpha}$ vs. $V_{\\beta}$ (Vrefs)", fontsize=16)
ax3.set_xlabel("$V_{\\alpha}$ (X-axis)", fontsize=14)
ax3.set_ylabel("$V_{\\beta}$ (Y-axis)", fontsize=14)
ax3.grid(True)
ax3.axhline(0, color='black', linewidth=0.5, linestyle='--')  # X-axis
ax3.axvline(0, color='black', linewidth=0.5, linestyle='--')  # Y-axis
ax3.legend()

# Plot 4: Theta over time
ax4 = plt.subplot(6, 1, 4, sharex=ax1)
ax4.plot(indices[0:10000], np.degrees(theta[0:10000]), label='$\\theta$ (Angle)', color='orange', linewidth=2)
ax4.set_title("Angle ($\\theta$) of the Vector Over Time", fontsize=16)
ax4.set_ylabel("Angle (Degrees)", fontsize=14)
ax4.grid(True)
ax4.legend()

# Plot 5: Sector over time
ax5 = plt.subplot(6, 1, 5, sharex=ax1)
ax5.step(indices[0:10000], sector[0:10000], label='Sector', color='teal', linewidth=2, where='post')
ax5.set_title("Sector Over Time", fontsize=16)
ax5.set_xlabel("Index", fontsize=14)
ax5.set_ylabel("Sector", fontsize=14)
ax5.grid(True)
ax5.legend()

# Plot 6: Vrefs magnitude over time
ax6 = plt.subplot(6, 1, 6, sharex=ax1)
vrefs_magnitude = np.sqrt(vrefs_valpha**2 + vrefs_vbeta**2)
ax6.plot(indices[:len(vrefs_magnitude)], vrefs_magnitude, label='Vrefs Magnitude', color='darkblue', linewidth=2)
ax6.set_title("Vrefs Magnitude Over Time", fontsize=16)
ax6.set_xlabel("Index", fontsize=14)
ax6.set_ylabel("Magnitude", fontsize=14)
ax6.grid(True)
ax6.legend()

# Adjust layout and show the plots
plt.tight_layout()
plt.show()
