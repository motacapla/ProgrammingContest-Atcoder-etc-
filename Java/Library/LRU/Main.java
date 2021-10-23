import java.util.*;
import java.util.stream.Collectors;

class Main {
    // doubly linked list having key and value
    static class Node{
        Node prev;
        Node next;
        int key;
        int value;
    
        Node(int key, int value){
            this.key = key;
            this.value = value;
        }
    }

    static class LRUcache {
        Node head = new Node(-1, -1);
        Node tail = new Node(-1, -1);
        Map<Integer, Node> map = new HashMap<>();
        int CACHE_SIZE;

        LRUcache(int cacheSize) {
            CACHE_SIZE = cacheSize;
            join(head, tail);
        }

        private void join(Node n1, Node n2){
            n1.next = n2;
            n2.prev = n1;
        }

        private void moveToHead(Node node) {
            Node nextNode = head.next;
            join(head, node);
            join(node, nextNode);
        }

        public Integer get(Integer key) {
            if (!map.containsKey(key)) {
                return -1;
            }
            Node node = map.get(key);
            join(node.prev, node.next);
            moveToHead(node);

            return node.value;
        }

        public void put(Integer key, Integer value) {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                join(node.prev, node.next);
                moveToHead(node);
                node.value = value;
                return;               
            }
            if (CACHE_SIZE == map.size()) {
                // 削除
                map.remove(tail.prev.key);
                join(tail.prev.prev, tail);
            }
            Node node = new Node(key, value);
            moveToHead(node);
            map.put(key, node);
        }
    }

    public static void main(String[] args) {
        int cacheSize = 4;
        LRUcache lru = new LRUcache(cacheSize);

        Integer noValue = lru.get(0);
        System.out.println("noValue should be -1 : " + noValue);

        lru.put(1,1);
        lru.put(2,2);
        lru.put(3,3);
        lru.put(4,4);

        Integer existingValue = lru.get(3);
        System.out.println("existingValue should exist : " + existingValue);


        lru.put(5,5);


        Integer removedValue = lru.get(1);
        System.out.println("existingValue should NOT exist : " + removedValue);

        return;
    }
}
