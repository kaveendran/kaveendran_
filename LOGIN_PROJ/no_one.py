#login system + signup system 
#login/Register system
from getpass import getpass
import maskpass
spacing=15
def register():
    db=open("data.txt",'r+')
    usr_name=input(" "*spacing +"ENTER NAME: ")
    usr_pass1=maskpass.askpass(" "*spacing +"ENTER password: ")
    usr_pass2=maskpass.askpass(" "*spacing +"ENTER password again: ")

    #compare 2 passwords 
    if usr_pass1 != usr_pass2:
        print(" "*spacing +"Passwords doesnt match")
        register()
    else:
        dictionary={}
        new_list_data=db.readlines()
        for data in new_list_data:
            data_string = data.strip().split()
            dictionary[data_string[0]]=data_string[1]

        for name, password in dictionary.items():
            if name ==usr_name:
                print(" "*spacing +"name taken enter another name...")

                register()
        else:
            db.write(usr_name+" "+usr_pass1+"\n")

            print(" "*spacing +"Registration successfull...")

    db.close()
    entry_screen()




# login


def login():
    usr_name=maskpass.askpass(" "*spacing +"Enter Name: ")
    usr_password=maskpass.askpass(" "*spacing +"Enter Password: ")


    db = open("data.txt",'r')
    
    new_list_data=db.readlines()
    #print(new_list_data)
    data_lst=[]
    dictionary_={}
    for data in new_list_data:
        
        
        data_string = data.strip().split()
        
        dictionary_[data_string[0]]=data_string[1]
     
    
    for name,password in dictionary_.items():

        if name==usr_name and password==usr_password:
            print(" "*spacing +"Login Successfull.........")

            msg_opt =input(" "*spacing +"S/R:")
            msg_opt=msg_opt.upper()
            
            secret_msg_save(msg_opt,usr_name)
            

        
    db.close()


def secret_msg_save(opt,name):
    msg_=open("msg.txt",'r+')
    msg_dict={}
    
    if opt =="S":

        
        print("-------------------- Secret message-------------------")
        msg=maskpass.askpass(" "*spacing +"Enter msg:")
        out = msg_.write(name +" "+ msg+"\n")
        if out>0:
            print(" "*spacing +"YOUR MSG STORED SUCCESSFULLY........!")
        else :
            print(" "*spacing +"Error occured....")
            entry_screen()
        
    elif opt=="R":
        print(" "*spacing +"---------------------Your message----------------------")
        reas_msg= msg_.readlines()

        

        for msgs in reas_msg:
            strings_=msgs.strip().split()
            msg_dict[strings_[0]]=strings_[1]
        
        for nme,msg in msg_dict.items():
            print(" "*spacing + msg)

    msg_.close()
    entry_screen()




#ask user for register or login 

def entry_screen():
    


    print(" "*spacing +"""
                                               
                                            
   _____ ______ _____ _    _ _____  _____ ________     __ 
  / ____|  ____/ ____| |  | |  __ \|_   _|  ____\ \   / / 
 | (___ | |__ | |    | |  | | |__) | | | | |__   \ \_/ /  
  \___ \|  __|| |    | |  | |  _  /  | | |  __|   \   /   
  ____) | |___| |____| |__| | | \ \ _| |_| |       | |    
 |_____/|______\_____|\____/|_|  \_|_____|_|       |_|    
                                                          
                               SECURIFY V1.0                            

         ============================================================================================= """)

    input_=input(" "*spacing +"LOGIN/SIGNUP: ")

    M_input = input_.upper()

    if M_input == "LOGIN":
        print(" "*spacing +"------------------------LOGIN------------------------")
        login()

    elif M_input =="SIGNUP":
        print(" "*spacing +"------------------------SIGNUP----------------------------------------")
        register()
    else:
        print(" "*spacing +"Restarting the programme")
        entry_screen()



entry_screen()







