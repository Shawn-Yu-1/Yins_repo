char* removeDuplicateLetters(char* s) {   //����ջ�ṹ���л��ݣ�����һ��count��ÿ����ĸ��������ͳ�ƣ���val����Ƿ�����ջ��
    char* temp = (char*)malloc(27 * sizeof(char));
    int count[130];
    int val[130];
    int i, j = 0, lenth;
    for (i = 80; i < 130; i++) {
        count[i] = 0;
        val[i] = 0;
    }
    lenth = strlen(s);
                                                        // printf("%d",lenth);
    for (i = 0; i < lenth; i++) {
        count[s[i]] = count[s[i]] + 1;
                                                            // putchar(s[i]);
    }
    temp[j] = s[0];
    val[s[0]] = 1;
    for (i = 1; i < lenth; i++) {
        if (val[s[i]]) {  //����ջ��ֱ������
            count[s[i]] -= 1;
            continue;
        }
        //if (count[s[i]] == 0)
      ///      continue;


        for (; j >= 0; j--) {
            //if(s[i] == temp[j]){
            //count[s[i]] = count[s[i]] -1;
            //break;
            //}

            if (s[i] > temp[j]) {       //����ջ��Ԫ��ֱ�Ӽ���
                temp[++j] = s[i];
                val[s[i]] = 1;
                break;
            }

            if (temp[j] > s[i]) {       //С��ջ��Ԫ�أ��������Ԫ�ؾ��ѳ�ս����
                if (count[temp[j]] == 1) {
                    temp[++j] = s[i];
                    val[s[i]] = 1;
                    break;
                }
                count[temp[j]] = count[temp[j]] - 1;
                val[temp[j]] = 0;
            }
        }
        if (j == -1) {
            temp[++j] = s[i];
            val[s[i]] = 1;
        }

    }
    temp[++j] = '\0';
    return temp;
}