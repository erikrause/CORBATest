package CORBATest;


/**
* CORBATest/EchoHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from echo.idl
* 7 ������� 2022 �. 16:54:27 YEKT
*/

abstract public class EchoHelper
{
  private static String  _id = "IDL:CORBATest/Echo:1.0";

  public static void insert (org.omg.CORBA.Any a, CORBATest.Echo that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static CORBATest.Echo extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (CORBATest.EchoHelper.id (), "Echo");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static CORBATest.Echo read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_EchoStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, CORBATest.Echo value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static CORBATest.Echo narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof CORBATest.Echo)
      return (CORBATest.Echo)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      CORBATest._EchoStub stub = new CORBATest._EchoStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

  public static CORBATest.Echo unchecked_narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof CORBATest.Echo)
      return (CORBATest.Echo)obj;
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      CORBATest._EchoStub stub = new CORBATest._EchoStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}
