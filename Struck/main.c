#include <stdio.h>
struct students{
    char *name;
    int num;
    int age;
    char group;
    float score;
}sut1,sut2 = {"login",19,20,'A',2.7};
/*
  ע�⣺
  1.��β�ֺ�
  2.��Ա��������Ҫ��ʼ��
*/
//�ṹ�忼��㣺��ռ�ڴ��С���ֽڣ�
//�ڴ������洢����������ͬ
//�ӵ�����ȡ���ڴ�ʹ��  ԭ�򣺰���������������ȡ����֮���Žṹ���е��������͡�
int main()
{
/*
    �ṹ��   ö��    ������
    �����壺���С�ˣ��ײ�C���Կ�����/ö����

    ���Աȣ�����ͽṹ������
    �ṹ�壺һЩ��ͬ�������ݵļ���
    struct XXX{};

*/
    sut1.name = "login";
    printf("%s",sut1.name);


    //ʵ��Ӧ�ã�����һ���������в�ͬ���������͵�����
    //��������  ��ָ����
    struct students arr[5] = {sut1,sut2};
    return 0;
    //�ṹ���׼д����typedef struct contact{}Contact,*Pcontact;
}
