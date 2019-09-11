


# private: returns the HIGH pin for a given node
def chuckhi(node, pinCount):
    node = int( node )
    pinCount = int( pinCount )
    result = int((node-1)/pinCount)
    return result


# private: returns the LOW pin for a given node
def chucklo( node, pinCount):
    node = int( node )
    pinCount = int( pinCount )
    result =  int( (node-1)%(pinCount-1) )
    if(result >= chuckhi(node, pinCount)):
        result+=1
    return result


for light in range(1, 13):
    print(f'node {light}: {chuckhi(light,4)}+  {chucklo(light,4)}-')

	
	
	




