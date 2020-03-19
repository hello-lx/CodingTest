/* Java
public class LoadBalancer {
    private List<Integer> list;
    private HashMap<Integer, Integer> serverToIndex;
    
    public LoadBalancer() {
                                // serverId, Index;
        serverToIndex = new HashMap<Integer, Integer>();
        list = new ArrayList<Integer>();
    }

//      * @param server_id: add a new server to the cluster
//      * @return: nothing
    public void add(int server_id) {
        list.add(server_id);
        int index = list.size() - 1;
        serverToIndex.put(server_id, index);
    }

//      * @param server_id: server_id remove a bad server from the cluster
//      * @return: nothing
    public void remove(int server_id) {
        int lastIndex = list.size() - 1;
        int lastServerId = list.get(lastIndex);
        int badIndex = serverToIndex.get(server_id);
        
        // 一定要考虑remove的就是最后一个的情况；
        if(badIndex == lastIndex) { 
            list.remove(lastIndex);
            serverToIndex.remove(server_id);
        } else { 
            // 然后考虑remove是中间的情况；
            list.set(badIndex, lastServerId);
            serverToIndex.put(lastServerId, badIndex);
            list.remove(lastIndex);
            serverToIndex.remove(server_id);
        }
    }
 
//     * @return: pick a server in the cluster randomly with equal probability
    public int pick() {
        int n = list.size();
        Random random = new Random();
        int randomIndex = random.nextInt(n);
        return list.get(randomIndex);
    }
}
*/
