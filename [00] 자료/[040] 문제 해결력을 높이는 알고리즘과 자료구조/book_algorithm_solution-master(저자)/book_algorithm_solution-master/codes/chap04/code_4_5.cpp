int fibo(int N) {
    // �١���������
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // �Ƶ��ƤӽФ�
    return fibo(N - 1) + fibo(N - 2);
}
