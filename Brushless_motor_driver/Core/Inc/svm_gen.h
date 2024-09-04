/*
 * svm_gen.h
 *
 *  Created on: Sep 3, 2024
 *      Author: Sashreek
 */

#ifndef INC_SVM_GEN_H_
#define INC_SVM_GEN_H_


#include <vector>

class SVMPWMGenerator {
public:
    // Constructor
    SVMPWMGenerator(double switchingFrequency, double modulationIndex);

    // Destructor
    ~SVMPWMGenerator();

    // Set the switching frequency (in Hz)
    void setSwitchingFrequency(double frequency);

    // Get the current switching frequency (in Hz)
    double getSwitchingFrequency() const;

    // Set the modulation index (typically between 0 and 1)
    void setModulationIndex(double index);

    // Get the current modulation index
    double getModulationIndex() const;

    // Generate the PWM signals for a given three-phase voltage reference (Va, Vb, Vc)
    void generatePWM(double Va, double Vb, double Vc, std::vector<double>& pwmA, std::vector<double>& pwmB, std::vector<double>& pwmC);

    // Get the current duty cycles for each phase
    void getDutyCycles(double& dutyA, double& dutyB, double& dutyC) const;

private:
    // Private member functions
    void calculateDutyCycles(double Va, double Vb, double Vc);

    // Private member variables
    double switchingFrequency;   // Switching frequency of the PWM
    double modulationIndex;      // Modulation index
    double dutyCycleA;           // Duty cycle for phase A
    double dutyCycleB;           // Duty cycle for phase B
    double dutyCycleC;           // Duty cycle for phase C
};



#endif /* INC_SVM_GEN_H_ */
