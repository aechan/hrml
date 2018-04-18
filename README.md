# HRML Parser
HRML comes from a [hackerrank challenge](https://www.hackerrank.com/challenges/attribute-parser/problem_) that I maybe took too far.. 

The HRML markup specification is a very simple markup language consisting of tags which can have string attributes that are represented as key-value pairs.

## Tags
There are 3 types of valid tags that follow the formats below:
1. Empty opener tag - simply defines a new tag and the tag's name
    `<tag-name>`
2. Opener tag with attributes - the opener tag can hold N number of attributes
    `<tag-name attribute1-name="some data" attribute2-name="more data" ... attributeN-name="final data">`
3. Closing tag - defines the closing of the tag's scope
    `</tag-name>`

Tags can be nested like so:
```
<tag1-name>
    <tag2-name>
    </tag2-name>
</tag1-name>
```

## Querying data
Using a HRML parser like the one given in this repo, data can be queried from these tags using simple commands.

If we had a HRML file containing the following markup:
```
<tag1-name attr1="world">
    <tag2-name attr2="hello">
    </tag2-name>
</tag1-name>
```
We could write a query to print out 
```
hello
world
```
like so:
```
tag1-name.tag2-name~attr2
tag1-name~attr1
```

In general the format for querying data is:
```
tag1.tag2.tag3~attribute // will get the value associated with the 3rd nested tag's attribute
```