import java.util.*;
public class Main
{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter confidence");
        double conf = sc.nextDouble();
        System.out.println("Enter support");
        int support = sc.nextInt();

        System.out.println("Enter the number of transactions");
        int n = sc.nextInt();
        System.out.println("Enter the number of items");
        int itemCount = sc.nextInt();
        List<Character> items = new ArrayList<>();
        for(int i=0;i<itemCount;i++)
            items.add((char)(65+i));

        HashMap<Integer,List<Character>> transactions = new HashMap<>();
        for(int i=0;i<n;i++){
            System.out.println("Enter the items for transaction "+(i+1));
            List<Character> arr = new ArrayList<>();
            for(int j=0;j<itemCount;j++){
                System.out.print("Is "+items.get(j)+" present? ");
                int c = sc.nextInt();
                if(c!=0)
                    arr.add(items.get(j));
            }
            transactions.put(i,arr);
        }
        for(int i=0;i<n;i++){
            System.out.print("Items in transaction "+i+": ");
            for(int j=0;j<transactions.get(i).size();j++)
                System.out.print(transactions.get(i).get(j)+" ");
            System.out.println();
        }

        HashMap<Set<Character>,Integer> rules = new HashMap<>();
        for(int i=0;i<itemCount;i++){
            int k=0;
            for(int j=0;j<transactions.size();j++){
                if(transactions.get(j).contains(items.get(i)))
                    k++;
            }
            rules.put(Collections.singleton(items.get(i)),k);
        }
        for(Set<Character> ch:rules.keySet()) {
            System.out.println(ch + " " + rules.get(ch));
        }

        int size = rules.size();
        while(size > 0 && --itemCount>0){
            for(Set<Character> ch : new ArrayList<>(rules.keySet())){
                if(rules.get(ch)<support)
                    rules.remove(ch);
            }

            HashMap<Set<Character>,Integer> temp = new HashMap<>(rules);

            for(Set<Character> ch : new ArrayList<>(rules.keySet())){
                for(Set<Character> c : new ArrayList<>(rules.keySet())){
                    Set<Character> set = new HashSet<>(ch);
                    set.addAll(c);
                    if(temp.containsKey(set))
                        continue;
                    int k = 0;
                    for(int i : transactions.keySet()) {
                        boolean flag = true;
                        List<Character> itms = transactions.get(i);
                        for(Character s : set) {
                            if (!itms.contains(s)) {
                                flag = false;
                                break;
                            }
                        }
                        if(flag)
                            k++;
                    }
                    temp.put(set,k);
                }
            }
            rules = temp;

            System.out.println("old: "+size+" new: "+rules.size());
            size = rules.size() - size;
            itemCount--;
        }
        for(Set<Character> ch : new ArrayList<>(rules.keySet())){
            if(rules.get(ch)<support)
                rules.remove(ch);
        }

        System.out.println("Frequent items are:");
        for(Set<Character> ch : rules.keySet()) {
            System.out.println(ch + ": " + rules.get(ch));
        }

        System.out.println("Association rules are:");
        for(Set<Character> s : new ArrayList<>(rules.keySet())){
            Set<Character> t = new HashSet<>(s);
            for(Character c : s){
                t.remove(c);
                if(t.size() == 0)
                    break;
                float c1 = rules.get(s) * 1.0f / rules.get(Collections.singleton(c));
                if(c1>conf) {
                    System.out.println(c+"->"+t+" = "+c1);
                }
                c1 = rules.get(s) * 1.0f / rules.get(t);
                if(c1>conf) {
                    System.out.println(t+"->"+c+" = "+c1);
                }
            }
        }
    }
}
