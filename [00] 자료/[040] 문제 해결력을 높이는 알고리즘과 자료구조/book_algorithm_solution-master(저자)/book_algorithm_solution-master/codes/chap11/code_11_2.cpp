int root(int x) {
    if (par[x] == -1) return x; // x �����ξ��� x ��ľ���֤�
    else return par[x] = root(par[x]); // x �ο� par[x] �򺬤����ꤹ��
}
