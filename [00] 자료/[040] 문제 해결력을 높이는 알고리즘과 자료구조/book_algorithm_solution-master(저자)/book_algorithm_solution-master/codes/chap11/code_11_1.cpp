int root(int x) {
    if (par[x] == -1) return x; // x �����ξ��� x ��ľ���֤�
    else return root(par[x]); // x �����Ǥʤ��ʤ�Ƶ�Ū�˿Ƥؤȿʤ�
}
