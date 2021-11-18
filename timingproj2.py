import numpy as np
import matplotlib.pyplot as plt

array_list_get = np.loadtxt("array_list_get.txt")
# array_list_insert = np.loadtxt("array_list_insert.txt")
linked_list_get = np.loadtxt("linked_list_get.txt")
# linked_list_insert = np.loadtxt("linked_list_insert.txt")

fig, ax = plt.subplots(2, 2, sharex=True, sharey=True)
ax[0, 0].loglog(array_list_get.T[0], array_list_get.T[1], label="Time")
# 0.005 is arbitrary. Please try to adjust this value so that it aligns
# well with you results
ax[0, 0].loglog(array_list_get.T[0], 0.035 * np.ones_like(array_list_get.T[0]), label="O(1)", linestyle="--") ##edited to 00.35 
ax[0, 0].set_title("ArrayList (get)")


# ax[0, 1].loglog(array_list_insert.T[0], array_list_insert.T[1], label="Time")
# 0.001 is arbitrary. Please try to adjust this value so that it aligns
# well with you results

# ax[0, 1].loglog(array_list_insert.T[0], 0.001 * array_list_insert.T[0],label="O(n)", linestyle="--")
# ax[0, 1].set_title("ArrayList (insert)")

ax[1, 0].loglog(linked_list_get.T[0], linked_list_get.T[1])
ax[1, 0].set_title("LinkedList (get)")
# ax[1, 1].loglog(linked_list_insert.T[0], linked_list_insert.T[1])
# ax[1, 1].set_title("LinkedList (insert)")

for axi in ax.flatten():
    axi.legend()
    axi.grid()
fig.savefig("arraylist_vs_linkedlist.png")