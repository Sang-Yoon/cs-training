import numpy as np

t = np.array([-0.0578354486528, 0.017834612968, 0.305319170368])
quarternion = np.array([0.963634807366, -0.0229766225701, 0.018320236452, 0.265601961185])
E_1 = quarternion[0]
E_2 = quarternion[1]
E_3 = quarternion[2]
E_4 = quarternion[3]

R = np.zeros((3, 3))
R[0, 0] = 1-2*E_2**2-2*E_3**2
R[0, 1] = 2*(E_1*E_2-E_3*E_4)
R[0, 2] = 2*(E_1*E_3+E_2*E_4)
R[1, 0] = 2*(E_1*E_2+E_3*E_4)
R[1, 1] = 1-2*E_1**2-2*E_3**2
R[1, 2] = 2*(E_2*E_3-E_1*E_4)
R[2, 0] = 2*(E_1*E_3-E_2*E_4)
R[2, 1] = 2*(E_2*E_4+E_1*E_4)
R[2, 2] = 1-2*E_1**2-2*E_2**2
print(R)