PGDMP     2                    x         	   drevesina    12.2    12.2     -           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            .           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            /           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            0           1262    16663 	   drevesina    DATABASE     �   CREATE DATABASE drevesina WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'Russian_Russia.1251' LC_CTYPE = 'Russian_Russia.1251';
    DROP DATABASE drevesina;
                postgres    false            1           0    0    DATABASE drevesina    ACL     l   REVOKE CONNECT,TEMPORARY ON DATABASE drevesina FROM PUBLIC;
REVOKE ALL ON DATABASE drevesina FROM postgres;
                   postgres    false    2864            �            1259    16665 
   polzovatel    TABLE     �   CREATE TABLE public.polzovatel (
    id integer NOT NULL,
    rolpolzov integer NOT NULL,
    "FIO" character varying NOT NULL,
    login character varying NOT NULL,
    pass character varying NOT NULL
);
    DROP TABLE public.polzovatel;
       public         heap    postgres    false            �            1259    16671    porodadrevesini    TABLE     k   CREATE TABLE public.porodadrevesini (
    id character varying NOT NULL,
    opisanie character varying
);
 #   DROP TABLE public.porodadrevesini;
       public         heap    postgres    false            �            1259    16677    postavka    TABLE     �   CREATE TABLE public.postavka (
    id integer NOT NULL,
    date date,
    idporodi character varying NOT NULL,
    kolichestvo integer NOT NULL,
    primechanie character varying,
    idzakazchik integer NOT NULL,
    idpostavchik integer NOT NULL
);
    DROP TABLE public.postavka;
       public         heap    postgres    false            �            1259    16683    postavshiki    TABLE     x   CREATE TABLE public.postavshiki (
    id integer NOT NULL,
    role integer NOT NULL,
    opisanie character varying
);
    DROP TABLE public.postavshiki;
       public         heap    postgres    false            �            1259    16695    rolepolzovatel    TABLE     `   CREATE TABLE public.rolepolzovatel (
    id integer NOT NULL,
    opisanie character varying
);
 "   DROP TABLE public.rolepolzovatel;
       public         heap    postgres    false            �            1259    16689    rolepostavchika    TABLE     a   CREATE TABLE public.rolepostavchika (
    id integer NOT NULL,
    opisanie character varying
);
 #   DROP TABLE public.rolepostavchika;
       public         heap    postgres    false            %          0    16665 
   polzovatel 
   TABLE DATA           G   COPY public.polzovatel (id, rolpolzov, "FIO", login, pass) FROM stdin;
    public          postgres    false    202   �       &          0    16671    porodadrevesini 
   TABLE DATA           7   COPY public.porodadrevesini (id, opisanie) FROM stdin;
    public          postgres    false    203   H       '          0    16677    postavka 
   TABLE DATA           k   COPY public.postavka (id, date, idporodi, kolichestvo, primechanie, idzakazchik, idpostavchik) FROM stdin;
    public          postgres    false    204   �       (          0    16683    postavshiki 
   TABLE DATA           9   COPY public.postavshiki (id, role, opisanie) FROM stdin;
    public          postgres    false    205   �       *          0    16695    rolepolzovatel 
   TABLE DATA           6   COPY public.rolepolzovatel (id, opisanie) FROM stdin;
    public          postgres    false    207          )          0    16689    rolepostavchika 
   TABLE DATA           7   COPY public.rolepostavchika (id, opisanie) FROM stdin;
    public          postgres    false    206   Y       �
           2606    16702    polzovatel polzovatel_pkey 
   CONSTRAINT     X   ALTER TABLE ONLY public.polzovatel
    ADD CONSTRAINT polzovatel_pkey PRIMARY KEY (id);
 D   ALTER TABLE ONLY public.polzovatel DROP CONSTRAINT polzovatel_pkey;
       public            postgres    false    202            �
           2606    16704 $   porodadrevesini porodadrevesini_pkey 
   CONSTRAINT     b   ALTER TABLE ONLY public.porodadrevesini
    ADD CONSTRAINT porodadrevesini_pkey PRIMARY KEY (id);
 N   ALTER TABLE ONLY public.porodadrevesini DROP CONSTRAINT porodadrevesini_pkey;
       public            postgres    false    203            �
           2606    16706    postavka postavka_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.postavka
    ADD CONSTRAINT postavka_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.postavka DROP CONSTRAINT postavka_pkey;
       public            postgres    false    204            �
           2606    16708    postavshiki postavshiki_pkey 
   CONSTRAINT     Z   ALTER TABLE ONLY public.postavshiki
    ADD CONSTRAINT postavshiki_pkey PRIMARY KEY (id);
 F   ALTER TABLE ONLY public.postavshiki DROP CONSTRAINT postavshiki_pkey;
       public            postgres    false    205            �
           2606    16710 $   rolepostavchika rolepostavchika_pkey 
   CONSTRAINT     b   ALTER TABLE ONLY public.rolepostavchika
    ADD CONSTRAINT rolepostavchika_pkey PRIMARY KEY (id);
 N   ALTER TABLE ONLY public.rolepostavchika DROP CONSTRAINT rolepostavchika_pkey;
       public            postgres    false    206            �
           2606    16712 !   rolepolzovatel rolpolzovatel_pkey 
   CONSTRAINT     _   ALTER TABLE ONLY public.rolepolzovatel
    ADD CONSTRAINT rolpolzovatel_pkey PRIMARY KEY (id);
 K   ALTER TABLE ONLY public.rolepolzovatel DROP CONSTRAINT rolpolzovatel_pkey;
       public            postgres    false    207            �
           2606    16713    postavka ogran    FK CONSTRAINT     �   ALTER TABLE ONLY public.postavka
    ADD CONSTRAINT ogran FOREIGN KEY (idporodi) REFERENCES public.porodadrevesini(id) NOT VALID;
 8   ALTER TABLE ONLY public.postavka DROP CONSTRAINT ogran;
       public          postgres    false    204    2714    203            �
           2606    16718    polzovatel ogran    FK CONSTRAINT     �   ALTER TABLE ONLY public.polzovatel
    ADD CONSTRAINT ogran FOREIGN KEY (rolpolzov) REFERENCES public.rolepolzovatel(id) NOT VALID;
 :   ALTER TABLE ONLY public.polzovatel DROP CONSTRAINT ogran;
       public          postgres    false    202    2722    207            �
           2606    16723    postavka ogran2    FK CONSTRAINT     �   ALTER TABLE ONLY public.postavka
    ADD CONSTRAINT ogran2 FOREIGN KEY (idpostavchik) REFERENCES public.postavshiki(id) NOT VALID;
 9   ALTER TABLE ONLY public.postavka DROP CONSTRAINT ogran2;
       public          postgres    false    204    205    2718            �
           2606    16728    postavka ogran3    FK CONSTRAINT     �   ALTER TABLE ONLY public.postavka
    ADD CONSTRAINT ogran3 FOREIGN KEY (idzakazchik) REFERENCES public.polzovatel(id) NOT VALID;
 9   ALTER TABLE ONLY public.postavka DROP CONSTRAINT ogran3;
       public          postgres    false    204    202    2712            %   J   x�3�4�0�[/���i�i�e $/̿�|a��]v\ثpa	�F�F\F@#NcNc.c ��b���� �      &   N   x��/�K��(˯��OUH��)��O�Q�KU(I�N�LT���)M� ��\s�\s8=��K��d'�T��r��qqq �-�      '   &   x�3�4200�50�52�t��4���4�4������ P��      (   .   x�3�4�0���.̸��{/������99�b���� t>�      *   /   x�3�LL���S�ͯJ-Q(+N�2�,-N-R�O�L��ˬ����� �*      )      x�3�tˬR��L��2���b���� `�     