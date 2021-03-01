# Algorithm_Hash_String-2-

### Hashing
- 특정 항목을 검색하고자 할 때, 탐색키를 이용한 산술적 연산을 이용해 키가 있는 위치를 계산하여 바로 찾아가는 방법
- Hash Function
  - 탐색키를 항목의 위치로 변환하는 함수
- Hash Table
  - 해싱 함수에 의해 반환된 주소의 위치에 항목을 저장한 표
- Search Hash
  - 해시 함수에 탐색키를 입력하여 주소를 구하고 구한 주소에 해당하는 해시 테이블로 이동
  - 해당 주소에 원하는 항목이 있으면 검색 성공, 없으면 실패
  - % 연산자에 자주 사용하는 소수 : 65521, 1000000003

### 충돌에 대한 해결방법
- Open Addressing(개방 주소법)
  - 해시 함수로 구한 주소에 빈 공간이 없어 충돌이 발생하면, 그 다음 공간에 빈 공간이 있는지 조사
  - 빈 공간이 있으면, 탐색키에 대한 항목을 저장
  - 빈 공간이 없으면, 공간이 나올 떄까지 탐색을 반복
- Chaining(체이닝)
  - 해시 테이블의 구조를 변경하여 각 버킷에 하나 이상의 키 값을 가지는 자료가 저장될 수 있도록 하는 방법
  - 하나의 버킷에 여러 개의 키 값을 저장하도록 하기 위해 연결리스트를 활용함
  
### String
- 응용
  - 정보처리
    - 키워드 기반의 웹페이지 검색
  - 유전체학
    - 유전자를 문자열 형태로 표현해서 처리
  - 통신 시스템
    - 텍스트 메시지나 e-mail, 전자책 다운로드 등
  - 프로그래밍 시스템
    - 컴파일러, 인터프리터 등

### 패턴매칭
- [문자열 비교(String-1)](https://github.com/KimUJin3359/Algorithm_String#패턴매칭)
- Rabin-Karp Algorithm
  - [코드](https://github.com/KimUJin3359/Algorithm_Hash_String-2-/blob/master/RabinKarp/RabinKarp/main.cpp)
  - 문자열 검색을 위해 해쉬 값 함수를 이용
  - 패턴 내의 문자들을 일일이 비교하는 대신에 패턴의 해시 값과 본문 안에 있는 하위 문자열의 해시 값만을 비교
  - 최악의 시간 복잡도는 O(MN)이지만 평균적으로는 선형에 가까운 빠른 속도를 가지는 알고리즘
  1) 찾고자 하는 문자열 길이만큼씩 원래 문자열에서 해쉬값을 계산
  2) 다음 해쉬값을 계산할 때, 기존에 읽었던 값을 이용하여 해쉬값을 구함
  3) 맨 앞자리 수만큼의 해쉬 값을 빼주고, 한칸을 왼쪽으로 옮긴 후(비트 연산) 새로운 값을 더해 새로운 해쉬 값을 구함
- KMP 알고리즘
  - [코드](https://github.com/KimUJin3359/Algorithm_Hash_String-2-/blob/master/KMP/KMP/main.cpp)
  - 불일치가 발생한 텍스트 문자열의 앞 부분에 어떤 문자가 있는지를 미리 알고 있으므로, 불일치가 발생한 앞 부분에 대하여 다시 비교하지 않고 매칭을 수행
  - 패턴을 전처리하여 다음 확인값을 구해, 잘못된 시작을 최소화함
  - 시간복잡도 : O(M + N)
  - PI Table : 비교 후 몇 번 index로 돌아갈 지를 기록해두는 table
  <img width="598" alt="ab" src="https://user-images.githubusercontent.com/50474972/109426116-26ec3d00-7a2f-11eb-9266-132db5b2e82b.png">
  - 돌아갈 index 계산법 : index - pi[index], index : 마지막에 비교했던 index 값

### Trie
- 각 간선은 하나의 문자에 대응하며, 같은 노드에 나오는 간선들은 같은 라벨을 갖지 않음
- 각 문자열은 단말 노드에 대응
- **아직 구현 및 이해를 완벽하게 하지 못했음으로 추후 정리**

### Suffix Trees
- 하나의 문자열로 만들어지는 모든 접미어들을 포함하는 트라이의 압축된 표현
- 문자열 연산에 필요한 알고리즘을 빠르게 구현
- 응용
  - 문자열 매칭(exact string matching)
  - 부분문자열 매칭(substring matching)
  - 최장 공통 부분 문자열(longest common substring)
- 길이가 s인 문자열 S의 suffix tree
  - 1부터 s까지 번호가 부여된 s개의 잎노드를 가짐
  - 루트를 제외한 내부 노드들은 최소 2개의 자식을 가짐
  - 각 간선은 문자열의 부분문자열 라벨이 부여됨
  - 현 노드에서 나가는 두 개의 간선이 동일한 문자로 시작하는 문자열 라벨을 가질 수 없음
  - 하나의 접미어가 다른 접미어의 접두어가 되는 경우를 표현하기 위해 문자열 S의 끝에 특수 문자($)을 추가
  ![suffix](https://user-images.githubusercontent.com/50474972/109494388-2b693200-7ad1-11eb-9a05-7241bbd671a4.png)

### Suffix Array
- [코드](https://github.com/KimUJin3359/Algorithm_Hash_String-2-/blob/master/SuffixArray/SuffixArray/main.cpp)
- Suffix Tree보다 메모리를 좀 더 효율적으로 사용하지만 다소 느림
- 텍스트의 인덱싱, 데이터 압축, Bio-Informatics 등의 다양한 분야에 사용
- Suffix Array의 복잡도
  - 접미어 배열은 O(n)의 메모리 크기
  - O(n logn) 시간에 생성
- Suffix Array의 장점
  - 생성 방법이 접미어 트리에 비해 간단
  - 적은 메모리로 구현 가능
- LCP 배열
  - 접미어 배열의 보조적인 자료 구조로 최장 공통 접두어(Longest Common Prefix) 배열
  - LCp 배열은 정렬된 접미어 배열에서 연속적인 2개의 접미어들 사이의 최장 공통 접두어의 길이를 저장
  - 접미어 배열의 순회나 패턴 매칭을 효율적으로 수행하는데 사용

### 문자열 압축
- 데이터 압축 : 거의 모든 응용 분야에서 사용
  - 텍스트, 이미지, 음원, 영상 데이터 등
- 대부분의 데이터 파일에는 중복이 존재
- 저장 공간 및 데이터 전송 시간의 절약
- 주요 압축 기법들
  - Run-Length Encoding
  - Huffman Coding
  - Lampel-Ziv-Welch Encoding
  - Arithmetic Coding
- 인코딩(encoding) : 데이터를 압축
- 디커딩(decoding) : 데이터를 복구
- 압축률 : 
 

