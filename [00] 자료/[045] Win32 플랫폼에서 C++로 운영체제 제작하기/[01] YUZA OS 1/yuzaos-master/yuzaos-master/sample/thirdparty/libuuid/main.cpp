#include <stdio.h>
#include <uuid.h>

int main(int argc, char* argv[])
{
    uuid_t uuid;

    //�����ĺ��� ����
    uuid_generate_time_safe(uuid);

    // uuid�� �ҹ��ڷ� ������ ���ڿ��� ��´�.
    char uuid_str[37];    
    uuid_unparse_lower(uuid, uuid_str);
    printf("UUID = %s\n", uuid_str);

    return 0;
}