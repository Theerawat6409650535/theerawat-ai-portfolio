โปรแกรมนี้มีทั้งหมด 5 ไฟล์ ประกอบไปด้วย 
1.ModifiedLinkedList.h
2.Operators.h
3.ModifiedLinkedList.cpp
4.Operators.cpp
5.main.cpp

ไฟล์ .h จากข้อ 1 และ 2 คือ interface class (abstract class) ของ 
ModifiedLinkedList class และ Operators class ตามลำดับ

ไฟล์ .cpp จากข้อ 3 เป็นการ implement method ต่างๆของ ModifiedLinkedList class
ภายใน ModifiedLinkedList class ประกอบไปด้วย
- คุณลักษณะต่างๆ (attributes)
    - Node : สมาชิกหนึ่งตัวใน Linked list โดยภายในสมาชิกแต่ละตัวประกอบไปด้วย 
        - data : ค่าของข้อมูลที่เก็บในสมาชิกตัวนั้น (ค่าเริ่มต้นผู้ใช้ต้องกำหนดเองเมื่อสร้าง)
        - next : ตำแหน่งของสมาชิกตัวถัดไปจากสมาชิกตัวนั้น (ค่ามีเริ่มต้นเป็น NULL เสมอ)
    - counter : ขนาดของ linked list
    - head : ตำแหน่งของสมาชิกตัวหน้าสุดใน Linked list
    - mid : ตำแหน่งของสมาชิกตัวตรงกลางใน Linked list
- พฤติกรรมต่างๆ (methods)
    - add : เพิ่มสมาชิกใหม่ใน linked list 
        - สร้าง node ใหม่ : จองพื้นที่ 1 node ใน Heap และกำหนดให้ค่าจาก parameter เป็นค่าของข้อมูล
        - กำหนดตำแหน่งถัดไปของ node เป็น head ปัจจุบัน
        - เปลี่ยนตำแหน่งของ head ปัจจุบันเป็น node ตัวใหม่
        - เพิ่มขนาดของ linked list 
        - กำหนดตำแหน่งให้ mid 
            - เช็คว่าขนาดของ linked list ปัจจุบันเป็นเลขคู่หรือเท่ากับ 1 ไหม ถ้าใช่ให้ขยับ mid
            - กำหนดให้ mid อยู่ตำแหน่งเดียวกับ head ก่อน
            - loop : เลื่อน mid จนกระทั่งอยู่ตำแหน่งกึ่งกลางของ linked list 
            ตัวอย่าง 
            counter = 0   head=NULL/mid=NULL
            counter = 1   head=[1]/mid=[1]
            counter = 2   head=[2]/mid=[2]
            counter = 3   head=[3]/mid=[2]
            counter = 4   head=[4]/mid=[3]
            สรุป head จะเปลี่ยนทุกครั้งที่ add แต่ mid จะเปลี่ยนเมื่อ counter เท่ากับ 1 หรือ เป็นเลขคู่
    - getData : นำค่าในสมาชิกทุกตัวและขนาดของ linked list ใส่ใน parameter
        - กำหนดให้ parameter size เป็น reference ของ counter
        - กำหนดให้ parameter data เป็น reference ของ pointer ชี้ไปที่ตำแหน่งแรกของ array : จองพื้นที่ array ใน Heap
        - สร้าง node ใหม่เพื่อคัดลอกตำแหน่งจาก head : node สามารถเข้าถึงสมาชิกตัวแรกได้
        - loop ตามจำนวนสมาชิกใน linked list
            - นำค่าจากสมาชิกแต่ละตัวใน linked list ไปเก็บใน array ผ่าน node ที่พึ่งสร้าง
            - เปลี่ยนตำแหน่งของ node ไปสมาชิกถัดไปจนกระทั่งครบทุกสมาชิก : node = NULL
    - clone : คัดลอก linked list แล้วคืนค่าตำแหน่งของ linked list ที่ถูก clone
        - สร้าง pointer ที่เก็บตำแหน่งของ linked list : จองพื้นที่สำหรับ linked list ใหม่ใน Heap
        - ดึงข้อมูลของ linked list ปัจจุบันใส่ใน array 
        - เพิ่มสมาชิกใน linked list ใหม่จากสมาชิกใน array : เริ่มจากตัวสุดท้าย
        - ลบ array : คืนเนื้อที่ใน Heap
        - คืนค่าตำแหน่งของ linked list ใหม่
        ตัวอย่าง
        linked list เดิม : 10 9 8 7 6 5 4 3 2 1
        array : 10 9 8 7 6 5 4 3 2 1
        linked list ใหม่ : 1
        linked list ใหม่ : 2 1
        linked list ใหม่ : 3 2 1
        ...
        linked list ใหม่ : 10 9 8 7 6 5 4 3 2 1
    - mergeWith : รวมสมาชิกใน linked list ปัจจุบันกับ linked list ที่รับจาก parameter คืนค่าตำแหน่งของ linked list ที่ถูกจับรวมกันแล้ว
        linked list ที่ถูกส่งมาใน parameter : addList
        linked list ปัจจุบัน : oldList
        - สร้าง pointer1 เก็บตำแหน่งของ linked list ที่ clone จาก addList
        - สร้าง pointer2 เก็บตำแหน่งของ linked list ที่ clone จาก oldList
        - สร้าง pointer3 คัดลอกตำแหน่ง head ของ linked list ที่ clone จาก addList
        - loop : จน pointer3 เป็นตำแหน่งสุดท้ายของสมาชิกใน linked list ที่ clone จาก addList
        - กำหนดให้ตัวถัดไปจาก pointer3 เป็น head ปัจจุบันของ linked list ที่ clone จาก oldList
        - เปลี่ยน head ของ linked list ที่ clone จาก oldList เป็นตำแหน่งของสมาชิกตัวแรกของ linked list ที่ clone จาก addList 
        - ลบ linked list ที่ clone จาก addList : คืนเนื้อที่ใน Heap
        - คืนตำแหน่งของ linked list ที่ clone จาก oldList ที่สมาชิกด้านในรวมกับสมาชิกของ linked list ที่ clone จาก addList แล้ว
        ตัวอย่าง
        linked list เดิม : 7 6 5 4 3 2 1
        linked list ที่ถูกส่งมาใน parameter : 10 9 8 
        linked list ใหม่ : 10 9 8 7 6 5 4 3 2 1
    - cut : ตัด linked list ปัจจุบันแล้วนำตำแหน่งของ linked list ที่ถูกตัดไปใส่ใน parameter
        - สร้าง pointer1 สำหรับเก็บตำแหน่ง linked list ที่ clone จาก linked list ปัจจุบัน 
        - สร้าง pointer2 สำหรับเก็บตำแหน่ง linked list ฝั่งหัว : จองพื้นที่ linked list ใน Heap
        - สร้าง pointer3 สำหรับเก็บตำแหน่ง linked list ฝั่งท้าย : จองพื้นที่ linked list ใน Heap
        - สร้าง node1 สำหรับเก็บตำแหน่ง head ของ linked list ที่ clone จาก linked list ปัจจุบัน
        - กำหนดให้ตำแหน่ง head ของ linked list ฝั่งหัวเท่ากับตำแหน่ง node1
        - loop ตามจำนวนสมาชิกใน linked list
            - เลื่อน node1 เป็นสมาชิกถัดไป
            - เมื่อพบว่าตำแหน่งปัจจุบันของ node1 เป็นตำแหน่งก่อนตำแหน่งที่ถูกตัด(ตำแหน่งสุดท้ายของ linked list ฝั่งหัว)
                - สร้าง node2 มาเก็บตำแหน่งปัจจุบันของ node1
                - กำหนดให้ตำแหน่งถัดไปของ node2 = NULL
            - เมื่อพบว่าตำแหน่งปัจจุบันของ node1 เป็นตำแหน่งหลังตำแหน่งที่ถูกตัด(ตำแหน่งแรกของ linked list ฝั่งท้าย)
                - กำหนดให้ตำแหน่ง head ของ linked list ฝั่งท้ายเท่ากับตำแหน่งปัจจุบันของ node1
        - ลบ linked list ที่ clone จาก linked list ปัจจุบัน : คืนเนื้อที่ใน Heap
        ตัวอย่าง
        linked list เดิม : 7 6 5 4 3 2 1 
        ตัดที่ตำแหน่งที่ 3 (ตำแหน่งแรก = 1)
        linked list ฝั่งหัว : 10 9 8 
        linked list ฝั่งท้าย : 7 6 5 4 3 2 1
    - removeAllNodes : คืนพื้นที่สมาชิกทุกตัว(ใน Heap)ของ linked list
        - loop จนกว่า head จะเท่ากับ NULL
            - สร้าง node มาเก็บตำแหน่งถัดไปของ head
            - ลบ head ตำแหน่งปัจจุบัน : คืนเนื้อสำหรับตำแหน่งที่ head ชี้ใน Heap 
            - เปลี่ยนตำแหน่ง head เป็นตำแหน่งเดียวกับ node : ตำแหน่งถัดไปจากตำแหน่ง head เดิม
            - ลบจำนวนสมาชิก
        - กำหนดให้ mid = NULL
        ตัวอย่าง
        loop 1
        [5] [4] [3] [2] [1] : head[5]/node[4]
            [4] [3] [2] [1] : head[4]
        loop 2
            [4] [3] [2] [1] : head[4]/node[3]
                [3] [2] [1] : head[3]
        loop 3
                [3] [2] [1] : head[3]/node[2]
                    [2] [1] : head[2]
        loop 4
                    [2] [1] : head[2]/node[1]
                        [1] : head[1]
        loop 5
                        [1] : head[1]/node=NULL
                            : head=NULL
    - print : พิมพ์สมาชิกทุกตัวใน linked list และระบุว่า mid มีค่าเท่าไหร่
        - สร้าง node มาเก็บตำแหน่ง head ปัจจุบัน
        - loop ตามจำนวนสมาชิกใน linked list
            - ถ้า node อยู่ตำแหน่งเดัยวกับ mid ให้พิมพ์ "[ค่าใน node]"
            - ถ้าไม่ให้พิมพ์ "ค่าใน node" และ " " (เว้นวรรค)
            - เปลี่ยนตำแหน่ง node เป็นตำแหน่งของสมาชิกตัวถัดไป
        - พิมพ์  ", Mid = :" และ "ค่าของ node ตำแหน่ง mid"
        ตัวอย่าง
        linked list : [5] [4] [3] [2] [1] 
        พิมพ์ : 5 4 [3] 2 1 , Mid = :3
