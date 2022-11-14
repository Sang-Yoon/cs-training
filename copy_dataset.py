# copy image files(depth, mask, rgb)
import shutil

img_folder = '/home/ksy/PVN3D/pvn3d/datasets/ycb/YCB_Video_Dataset/data/0100'
file_name = ['depth.png', 'label.png', 'color.png', 'meta.mat']

for i in range(4):
    for j in range(2, 201):
        source = img_folder + '/' + '000001-{}'.format(file_name[i])
        destination = img_folder + '/' + '{:06d}-{}'.format(j, file_name[i])
        shutil.copyfile(source, destination)

# meta.mat
import numpy as np
import scipy.io as scio

# mat_file_name = '{}'.format(img_folder) + '/' + '000001-meta.mat'
# meta = scio.loadmat(mat_file_name)

# R = np.array([[ 0.99827289, -0.05401393,  0.02310276],
#  [-0.03455037, -0.85785535, -0.51272846],
#  [ 0.04751331,  0.49968132, -0.85823993]])
# T = np.array([-0.0578354486528, 0.017834612968, 0.305319170368])

# poses = np.zeros([3, 4, 1])
# for i in range(3):
#     poses[i, 3, 0] = T[i]
#     for j in range(3):
#         poses[i, j, 0] = R[i, j]
        
# for i in range(1):
#     # r = meta['poses'][:, :, i][:, 0:3]
#     # t = np.array(meta['poses'][:, :, i][:, 3:4].flatten()[:, None])
#     r = poses[:, :, i][:, 0:3]
#     t = poses[:, :, i][:, 3:4].flatten()[:, None]

# cls = np.array([22]).astype('uint8')
# factor_depth = np.array([10000]).astype('uint16')
# dic = {'cls_indexes':cls, 'poses': poses, 'factor_depth':factor_depth}
# scio.savemat('/home/ksy/Desktop/000001-meta.mat', dic)

