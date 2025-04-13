#include <msgpack.h>
#include <stdio.h>

int main(void)
{
    //msgpack�� ���� ���� ����, �ʱ�ȭ
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    char szYuza[] = "YUZA OS";

    //����ȭ�� ���� ��Ŀ �غ�
    //msgpack_sbuffer_write �Լ��� �ݹ��Լ���.
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    //������ ��ŷ. 5���� ��ŷ�Ѵ�.
    msgpack_pack_array(&pk, 5);
    msgpack_pack_int(&pk, 12345); //int
    msgpack_pack_true(&pk); //bool
    msgpack_pack_str(&pk, strlen(szYuza)); //���ڿ�
    msgpack_pack_str_body(&pk, szYuza, strlen(szYuza));
    msgpack_pack_short(&pk, 12); // short
    msgpack_pack_char(&pk, 'a'); // char

    //������ȭ �׽�Ʈ
    msgpack_zone mempool;
    msgpack_zone_init(&mempool, 2048);

    msgpack_object deserialized;
    msgpack_unpack(sbuf.data, sbuf.size, NULL, &mempool, &deserialized);

    //��� ���
    msgpack_object_print(stdout, deserialized);
    printf("\n");

    msgpack_zone_destroy(&mempool);
    msgpack_sbuffer_destroy(&sbuf);

    return 0;
}